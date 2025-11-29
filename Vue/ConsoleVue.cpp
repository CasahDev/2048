//
// Created by sacha on 18/11/2025.
//

#include "ConsoleVue.h"

#include <iostream>
#include <cmath>

#include "Game/ConsoleGame.h"

ConsoleVue::ConsoleVue(const GameVM &game) : game_(std::move(game)) {
}

void ConsoleVue::move(const Direction direction) {
    game_.swipe(direction);
}

void ConsoleVue::display() const{
    ConsoleGame game(game_);
    std::cout << game;
}

bool ConsoleVue::check_for_loose() const {
    return game_.check_for_loose();
}

void ConsoleVue::display_lost() const {
    std::cout << "Partie perdue !" << std::endl;
    std::cout << "Score final: " << game_.get_score();
}

void ConsoleVue::display_won() const {
    std::cout << "Félicitation, vous avez attends le score de 2048 !";
}

bool ConsoleVue::check_for_win() const {
    return game_.check_for_win();
}
