//
// Created by sacha on 26/11/2025.
//

#pragma once
#include "GrilleVM.h"
#include "../Model/Game.h"


class GameVM {
    Game game_;

public:
    explicit GameVM(Game game);

    GrilleVM get_grille() const;
    unsigned long get_score() const;
};