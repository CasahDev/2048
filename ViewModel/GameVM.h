//
// Created by sacha on 26/11/2025.
//

#pragma once
#include "GrilleVM.h"
#include "../Model/Game.h"

class GameVM : public Observer, public Observable{
    Game &game_;

public:
    explicit GameVM(Game &game);

    GrilleVM get_grille() const;
    unsigned long get_score() const;

    void swipe(Direction direction);

    bool check_for_loose() const;

    bool check_for_win() const;

    void grid_changed() override;
};
