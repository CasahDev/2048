//
// Created by sacha on 18/11/2025.
//

#include "ConsoleVue.h"

#include <iostream>

#include "Game/ConsoleGame.h"

ConsoleVue::ConsoleVue(const GameVM &game) : game_(std::move(game)) {
}

void ConsoleVue::move(Direction direction) {
}

void ConsoleVue::Display() {
    ConsoleGame game(game_);
    std::cout << game;
}
