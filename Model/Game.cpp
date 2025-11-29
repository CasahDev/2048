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
    grille_.move(direction);

    // check_for_loose();
    grille_.insert_new_value();
}

bool Game::check_for_loose() const {
    int size = 0;
    for (const auto &val: grille_.get_cases() | std::views::values) {
        if (val.has_value()) {
            size++;
        }
    }

    return size == grille_.get_height() * grille_.get_width();
}

Grille Game::get_grille() const {
    return grille_;
}

unsigned long Game::get_score() const {
    return score_;
}