//
// Created by sacha on 17/11/2025.
//
#pragma once

#include "../Model/Direction.h"

class IVue {
public:
    virtual ~IVue() = default;

private:
    virtual void move(Direction direction) = 0;
    virtual void display() = 0;
    virtual bool check_for_loose() = 0;
    virtual void display_lost() = 0;
};