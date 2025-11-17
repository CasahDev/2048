//
// Created by sacha on 17/11/2025.
//

#include "Grille.h"

#include <ostream>
#include <stdexcept>

Grille::Grille(int width, int height) : width_(width), height_(height), cases_() {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            Coordinates coordinates(j, i);
            std::optional<Case> c;
            cases_.emplace(coordinates, c);
        }
    }
}

void Grille::swipe(Direction direction) {
    if (direction == Direction::Up || direction == Direction::Down) {
        swipe_vertically(direction == Direction::Up);
    } else {
        swipe_horizontally(direction == Direction::Right);
    }
}

std::unordered_map<Coordinates, std::optional<Case>> Grille::get_cases() {
    return cases_;
}

void Grille::swipe_vertically(bool up) {
    for (int i = 0; i < height_; i++) {
    }
}

void Grille::swipe_horizontally(bool right) {
    for (int i = 0; i < height_; i++) {
        int j = right * width_ - 1;
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

        // TODO: Décalage de toutes les cases vers la direction choisie
    }

    // Ajout d'une valeur dans une case disponible
    int size = 0;
    for (const auto &kv : cases_) {
        if (kv.second.has_value()) {
            size++;
        }
    }

    if (size == height_ * width_) {
        // loose
    } else {

    }

    bool found = false;
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
