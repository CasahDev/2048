//
// Created by sacha on 17/11/2025.
//

#include "Grille.h"

#include <cfloat>
#include <complex>
#include <iostream>
#include <ostream>
#include <random>
#include <ranges>
#include <stdexcept>

Grille::Grille(int width, int height) : width_(width), height_(height), cases_() {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            Coordinates coordinates(j, i);
            std::optional<Case> c;
            cases_.emplace(coordinates, c);
        }
    }

    max_ = 2;
}

void Grille::swipe(const Direction direction) {
    if (direction == Direction::Up || direction == Direction::Down) {
        swipe_vertically(direction == Direction::Up);
    } else {
        swipe_horizontally(direction == Direction::Right);
    }

    check_for_loose();
    insert_new_value();
}

std::unordered_map<Coordinates, std::optional<Case>> Grille::get_cases() const {
    return cases_;
}

void Grille::swipe_vertically(const bool up) {
    for (int i = 0; i < width_; i++) {
        int j = up * height_ - 1;
        while (j < height_ && j >= 0) {
            Coordinates coordinates(j, i);

            if (std::optional<Case> c = cases_.at(coordinates); c.has_value()) {
                int k = j + 1 - 2 * up;
                std::optional<Case> c2;

                Coordinates coordinates2(k, j);
                while (!c2.has_value() && k < height_ && k >= 0) {
                    coordinates2 = Coordinates(k, j);
                    c2 = cases_.at(coordinates2);
                    k += i - 2 * up;
                }

                if (c2) {
                    if (std::optional<Case> new_case = c->combine(c2.value()); new_case.has_value()) {
                        if (new_case->get_value() > max_) {
                            max_ = new_case->get_value();
                        }

                        cases_.emplace(coordinates, new_case);
                        j = k;
                        std::optional<Case> empty;
                        cases_.emplace(coordinates2, empty);
                    }
                }
            }
            j += 1 - up * 2;
        }

        int nextPos = 0;
        for (int x = 0; x < height_; x++) {
            Coordinates coordinates(x, i);
            if (std::optional<Case> c = cases_.at(coordinates); c.has_value()) {
                cases_.emplace(Coordinates(nextPos, i), c);
                nextPos++;
                std::optional<Case> empty;
                cases_.emplace(coordinates, empty);
            }
        }
    }
}

void Grille::swipe_horizontally(const bool right) {
    for (int i = 0; i < height_; i++) {
        int j = right * (width_ - 1);
        while (j < width_ && j >= 0) {
            Coordinates coordinates(j, i);

            if (std::optional<Case> c = cases_.at(coordinates); c.has_value()) {
                int k = j + 1 - 2 * right;
                std::optional<Case> c2;

                Coordinates coordinates2(k, j);
                while (!c2.has_value() && k < width_ && k >= 0) {
                    coordinates2 = Coordinates(k, j);
                    c2 = cases_.at(coordinates2);
                    k += i - 2 * right;
                }

                if (c2) {
                    if (std::optional<Case> new_case = c->combine(c2.value()); new_case.has_value()) {
                        if (new_case->get_value() > max_) {
                            max_ = new_case->get_value();
                        }

                        cases_.emplace(coordinates, new_case);
                        j = k;
                        std::optional<Case> empty;
                        cases_.emplace(coordinates2, empty);
                    }
                }
            }
            j += 1 - right * 2;
        }

        int nextPos = right * (width_ - 1);
        for (int x = 0; x < width_; x++) {
            Coordinates coordinates(x, i);
            if (std::optional<Case> c = cases_.at(coordinates); c.has_value()) {
                cases_.emplace(Coordinates(nextPos, i), c);
                nextPos += 1 - 2 * right;
                std::optional<Case> empty;
                cases_.emplace(coordinates, empty);
            }
        }
    }
}

void Grille::insert_new_value() {
    bool found = false;
    while (!found) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<> dist(1, std::nextafter(0, DBL_MAX));
        const int x = static_cast<int>(round(dist(mt))) % width_;
        const int y = static_cast<int>(round(dist(mt))) % height_;

        if (std::optional<Case> c = cases_.at(Coordinates(x, y)); !c.has_value()) {
            found = true;
            const long newValue = std::pow(
                2, static_cast<int>(round(dist(mt))) % static_cast<int>(round(log2(max_))) + 1);
            Case newCase(newValue);
            cases_.erase(Coordinates(x, y));
            cases_.emplace(Coordinates(x, y), newCase);
        }
    }
}

void Grille::check_for_loose() {
    // Ajout d'une valeur dans une case disponible
    int size = 0;
    for (const auto &val: cases_ | std::views::values) {
        if (val.has_value()) {
            size++;
        }
    }

    if (size == height_ * width_) {
        // loose
    } else {

    }
}

std::ostream &operator<<(std::ostream &os, const Grille &g) {
    for (int i = 0; i < g.height_; i++) {
        for (int j = 0; j < g.width_; j++) {
            Coordinates coordinates(j, i);

            if (std::optional<Case> c = g.cases_.at(coordinates); c.has_value()) {
                os << std::to_string(c.value().get_value());
            } else {
                os << "#";
            }
        }
        os << std::endl;
    }
    return os;
}