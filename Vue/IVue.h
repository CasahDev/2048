//
// Created by sacha on 17/11/2025.
//
#pragma once

#include "../Model/Direction.h"

class IVue {
public:
    virtual ~IVue() = default;
    [[noreturn]] void run();

private:
    virtual void move(Direction direction) = 0;
    virtual void display() const = 0;
    virtual bool check_for_loose() const = 0;
    virtual void display_lost() const = 0;
    virtual void display_won() const = 0;
    virtual bool check_for_win() const = 0;

    virtual void read_input() = 0;
};