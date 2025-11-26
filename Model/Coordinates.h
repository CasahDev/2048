//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <functional>


class Coordinates {
    int x_;
    int y_;

public:
    Coordinates(int x, int y);

    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;

    bool operator==(const Coordinates &c) const;
};