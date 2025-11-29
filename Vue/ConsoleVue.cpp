//
// Created by sacha on 18/11/2025.
//

#include "ConsoleVue.h"

#include <iostream>

#include "Game/ConsoleGame.h"

ConsoleVue::ConsoleVue(const GameVM &game) : game_(std::move(game)) {
}

void ConsoleVue::move(const Direction direction) {
    game_.swipe(direction);
}

void ConsoleVue::display() {
    ConsoleGame game(game_);
    std::cout << game;
}

bool ConsoleVue::check_for_loose() {
    return game_.check_for_loose();
}

void ConsoleVue::display_lost() {
    std::cout << "Partie perdue !";
}
