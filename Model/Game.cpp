//
// Created by sacha on 26/11/2025.
//

#include "Game.h"

Game::Game() : grille_(4, 4) {
    score_ = grille_.init();
}

void Game::swipe(const Direction direction) {
    grille_.swipe(direction);
}

Grille Game::get_grille() const {
    return grille_;
}

unsigned long Game::get_score() const {
    return score_;
}