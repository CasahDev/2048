//
// Created by sacha on 17/11/2025.
//

#include "Coordinates.h"

Coordinates::Coordinates(const unsigned int x, const unsigned int y) : x_(x), y_(y) {
}

unsigned int Coordinates::get_x() const {
    return x_;
}

unsigned int Coordinates::get_y() const {
    return y_;
}

bool Coordinates::operator==(const Coordinates &c) const {
    return x_ == c.get_x() && y_ == c.get_y();
}