//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "Case.h"
#include "Coordinates.h"
#include "Direction.h"


class Grille {
    void check_for_loose();
    void swipe_vertically(bool up);
    void swipe_horizontally(bool right);
    unsigned int width_;
    unsigned int height_;
    std::unordered_map<Coordinates, std::optional<Case>> cases_;

public:
    Grille(unsigned int width, unsigned int height);
    unsigned long init();
    unsigned long swipe(Direction direction);
    unsigned long insert_new_value();

    unsigned int get_width() const;
    unsigned int get_height() const;
    std::unordered_map<Coordinates, std::optional<Case>> get_cases() const;
};