//
// Created by sacha on 26/11/2025.
//

#pragma once

#include "Grille.h"


class Game {
protected:
    Grille grille_;
    unsigned long score_;

public:
    Game();
    void swipe(Direction direction);
    bool check_for_loose() const;

    Grille get_grille() const;
    unsigned long get_score() const;
};
