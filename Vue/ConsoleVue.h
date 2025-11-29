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

    void display() override;

    bool check_for_loose() override;
    void display_lost() override;
};