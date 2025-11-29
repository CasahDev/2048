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
    unsigned int width_;
    unsigned int height_;
    std::unordered_map<Coordinates, std::optional<Case>> cases_;

    void swipe(int outer_limit, int inner_limit, bool pack_to_start,
                          const std::function<Coordinates(int, int)>& get_coords);
public:
    Grille(unsigned int width, unsigned int height);
    unsigned long init();

    void move(Direction direction);
    unsigned long insert_new_value();

    unsigned int get_width() const;
    unsigned int get_height() const;
    std::unordered_map<Coordinates, std::optional<Case>> get_cases() const;
};