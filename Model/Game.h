//
// Created by sacha on 26/11/2025.
//

#pragma once

#include "Grid.h"


class Game {
protected:
    Grid grille_;
    unsigned long score_;

public:
    Game();
    void swipe(Direction direction);
    bool check_for_loose() const;
    bool check_for_win() const;

    Grid get_grille() const;
    unsigned long get_score() const;

};
