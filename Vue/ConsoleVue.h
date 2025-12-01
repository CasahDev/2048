//
// Created by sacha on 18/11/2025.
//
#pragma once

#include "IVue.h"
#include "../ViewModel/GameVM.h"


class ConsoleVue : IVue {
    GameVM game_;

public:
    explicit ConsoleVue(const GameVM &game);
    void move(Direction direction) override;

    void display() const override;

    bool check_for_loose() const override;
    void display_lost() const override;
    void display_won() const override;

    bool check_for_win() const override;

    void grid_changed() override;

    void read_input() override;
};
