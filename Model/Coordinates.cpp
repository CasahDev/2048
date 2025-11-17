//
// Created by sacha on 17/11/2025.
//

#include "Coordinates.h"

Coordinates::Coordinates(int x, int y) : x_(x), y_(y){
}

int Coordinates::get_x() const {
    return x_;
}

int Coordinates::get_y() const {
    return y_;
}
