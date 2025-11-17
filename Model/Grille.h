//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_GRILLE_H
#define TD2_GRILLE_H

#pragma once

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "Case.h"
#include "Coordinates.h"
#include "Direction.h"


class Grille
{
    int width_;
    int height_;
    std::unordered_map<Coordinates, std::optional<Case>> cases_;

    int max_;

    void insert_new_value();
    void swipe_vertically(bool up);
    void swipe_horizontally(bool right);
public:
    Grille(int width, int height);
    void swipe(Direction direction);

    friend std::ostream& operator<<(std::ostream &os, const Grille& g);

    std::unordered_map<Coordinates, std::optional<Case>> get_cases();
};


#endif //TD2_GRILLE_H