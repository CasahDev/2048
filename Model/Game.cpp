//
// Created by sacha on 26/11/2025.
//

#include "Game.h"

#include <ranges>

#include "../Vue/Game/ConsoleGame.h"

Game::Game() : grille_(4, 4) {
    score_ = grille_.init();
}

void Game::swipe(const Direction direction) {
    if (const int value = grille_.move(direction); value > score_) score_ = value;

    grille_.insert_new_value();
    notify_grid_changed();
}

bool Game::check_for_loose() const {
    int size = 0;
    for (const auto &val: grille_.get_cases() | std::views::values) {
        if (val.has_value()) {
            size++;
        }
    }

    bool can_combine = false;
    const auto cases = grille_.get_cases();
    for (int i = 0; i < grille_.get_height(); i++) {
        for (int j = 0; j < grille_.get_width(); j++) {
            Coordinates pos(i, j);
            if (std::optional<Box> c = cases.at(pos); c.has_value()) {
                if (j + 1 != grille_.get_height()) {
                    Coordinates botPos(i, j + 1 );

                    if (std::optional<Box> bot = cases.at(botPos); bot.has_value()) {
                        if (std::optional<Box> new_c = c->combine(bot.value()); new_c.has_value()) {
                            can_combine = true;
                        }
                    }
                }

                if (i + 1 != grille_.get_width()) {
                    Coordinates leftPos(i + 1, j);

                    if (std::optional<Box> left = cases.at(leftPos); left.has_value()) {
                        if (std::optional<Box> new_c = c->combine(left.value()); new_c.has_value()) {
                            can_combine = true;
                        }
                    }
                }

            }
        }
    }

    return size == grille_.get_height() * grille_.get_width() && !can_combine;
}

const Grid &Game::get_grille() const {
    return grille_;
}

unsigned long Game::get_score() const {
    return score_;
}

bool Game::check_for_win() const {
    return score_ > 10;
}
