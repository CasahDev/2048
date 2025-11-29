//
// Created by sacha on 26/11/2025.
//

#include "GameVM.h"

#include <cmath>

#include "GrilleVM.h"

GameVM::GameVM(Game game) : game_(std::move(game)){
}

GrilleVM GameVM::get_grille() const {
    GrilleVM g(game_.get_grille());
    return g;
}

unsigned long GameVM::get_score() const {
    return static_cast<unsigned long>(pow(2, game_.get_score()));
}

