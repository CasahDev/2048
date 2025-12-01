//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "Box.h"
#include "Coordinates.h"
#include "Direction.h"


class Grid {
    unsigned int width_;
    unsigned int height_;
    std::unordered_map<Coordinates, std::optional<Box>> cases_;

    unsigned long swipe(int outer_limit, int inner_limit, bool pack_to_start,
                        const std::function<Coordinates(int, int)> &get_coords);
    bool has_space() const;
public:
    Grid(unsigned int width, unsigned int height);
    unsigned long init();


    unsigned long move(Direction direction);
    unsigned long insert_new_value();

    unsigned int get_width() const;
    unsigned int get_height() const;

    const std::unordered_map<Coordinates, std::optional<Box>> &get_cases() const;
};