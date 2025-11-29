//
// Created by sacha on 29/11/2025.
//

#include "ConsoleGame.h"

#include <ostream>
#include <utility>

#include "ConsoleGrille.h"

ConsoleGame::ConsoleGame(GameVM game) : game_(std::move(game)) {
}

std::ostream &operator<<(std::ostream &os, ConsoleGame &g) {
    os << "Score actuel: " << g.game_.get_score() << std::endl;

    const ConsoleGrille grille(g.game_.get_grille());

    os << grille << std::endl << std::endl;

    return os;
}
