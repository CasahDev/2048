//
// Created by sacha on 18/11/2025.
//

#include "ConsoleVue.h"

#include <iostream>
#include <cmath>
#include <unistd.h>
#include <termios.h>
#include <cstdio>

#include "../Model/GameState.h"
#include "Game/ConsoleGame.h"

ConsoleVue::ConsoleVue(const GameVM &game) : game_(game) {
    termios t{};

    if (tcgetattr(STDIN_FILENO, &t) == -1) {
        perror("tcgetattr");
        throw std::invalid_argument("Console not compatible");
    }

    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &t) == -1) {
        perror("tcsetattr");
    }
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

void ConsoleVue::grid_changed() {
    display();

    if (check_for_loose()) {
        display_lost();
    }
    if (check_for_win()) {
        display_won();
    }
}

void ConsoleVue::read_input() {
    char key = 0;
    if (read(STDIN_FILENO, &key, 1) == 1) {
        std::optional<Direction> direction;

        switch (key) {
            case 'z':
                direction = Direction::Up;
                break;
            case 'q':
                direction = Direction::Left;
                break;
            case 's':
                direction = Direction::Down;
                break;
            case 'd':
                direction = Direction::Right;
                break;
            default: break;
        }

        if (direction.has_value()) {
            move(direction.value());
        }
    }
}