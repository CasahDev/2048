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

Grille::Grille(const unsigned int width, const unsigned int height) : width_(width), height_(height) {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            Coordinates coordinates(j, i);
            std::optional<Case> c;
            cases_.emplace(coordinates, c);
        }
    }
}

void Grille::move(const Direction direction) {
    if (direction == Direction::Up || direction == Direction::Down) {
        swipe(width_, height_, direction == Direction::Up,
                [this](const int moving, const int fixed) {
                    // Vertical: moving = ligne (y), fixed = colonne (x)
                    return Coordinates(fixed, moving);
                }
            );
    } else {
        swipe(height_, width_, direction != Direction::Right,
                [this](const int moving, const int fixed) {
                    // Horizontal: moving = colonne (x), fixed = ligne (y)
                    return Coordinates(moving, fixed);
                }
            );
    }
}

void Grille::swipe(const int outer_limit, const int inner_limit, const bool pack_to_start,
                          const std::function<Coordinates(int, int)>& get_coords) {

    // pack_to_start = true  -> On tasse vers l'index 0 (Haut ou Gauche)
    // pack_to_start = false -> On tasse vers l'index Max (Bas ou Droite)

    const int start = pack_to_start ? 0 : inner_limit - 1;
    const int end   = pack_to_start ? inner_limit : -1;
    const int step  = pack_to_start ? 1 : -1;

    for (int i = 0; i < outer_limit; i++) {
        // --- Phase 1 : Fusion (Merge) ---
        for (int j = start; j != end; j += step) {
            Coordinates currentPos = get_coords(j, i);

            if (auto c = cases_.at(currentPos); c.has_value()) {
                // On regarde la case suivante dans la direction du balayage
                int k = j + step;

                // Recherche du prochain voisin non vide
                std::optional<Case> neighbor;
                Coordinates neighborPos(0, 0); // Placeholder
                bool found = false;
                while (k != end && found == false) {
                    neighborPos = get_coords(k, i);
                    neighbor = cases_.at(neighborPos);
                    if (neighbor.has_value()) found = true;
                    k += step;
                }

                if (neighbor) {
                    if (auto new_case = c->combine(neighbor.value()); new_case.has_value()) {
                        cases_.erase(currentPos);
                        cases_.emplace(currentPos, new_case);
                        cases_.erase(neighborPos);
                        cases_.emplace(neighborPos, std::optional<Case>{}); // Vider l'ancienne case
                        j = k - step; // Optimisation pour sauter le cas traité si nécessaire
                    }
                }
            }
        }

        // --- Phase 2 : Décalage (Shift) pour combler les trous ---
        int writePos = start;
        for (int x = start; x != end; x += step) {
            Coordinates readPos = get_coords(x, i);

            if (auto c = cases_.at(readPos); c.has_value()) {
                if (x != writePos) { // Évite de copier sur soi-même
                    Coordinates targetPos = get_coords(writePos, i);
                    cases_.erase(targetPos);
                    cases_.emplace(targetPos, c);
                    cases_.erase(readPos);
                    cases_.emplace(readPos, std::optional<Case>{});
                }
                writePos += step;
            }
        }
    }
}

std::unordered_map<Coordinates, std::optional<Case> > Grille::get_cases() const {
    return cases_;
}

unsigned long Grille::insert_new_value() {

    unsigned long newValue = 0;
    if (has_space()) {
        bool found = false;
        while (!found) {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<> dist(0, std::max(width_, height_));
            const unsigned int x = static_cast<unsigned int>(round(dist(mt))) % width_;
            const unsigned int y = static_cast<unsigned int>(round(dist(mt))) % height_;

            if (std::optional<Case> c = cases_.at(Coordinates(x, y)); !c.has_value()) {
                found = true;
                newValue = static_cast<int>(round(dist(mt))) % 2 + 1;
                Case newCase(newValue);
                cases_.erase(Coordinates(x, y));
                cases_.emplace(Coordinates(x, y), newCase);
            }
        }
    }
    return newValue;
}

unsigned int Grille::get_width() const {
    return width_;
}

unsigned int Grille::get_height() const {
    return height_;
}

unsigned long Grille::init() {
    const unsigned long v1 = insert_new_value();
    const unsigned long v2 = insert_new_value();

    return std::max(v1, v2);
}

bool Grille::has_space() const {
    bool space = false;
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            Coordinates pos(i, j);
            if (!cases_.at(pos).has_value()) {
                space = true;
            }
        }
    }

    return space;
}
