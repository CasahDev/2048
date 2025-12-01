//
// Created by sacha on 29/11/2025.
//

#include "GrilleVM.h"

GrilleVM::GrilleVM(const Grid &grille) : grille_(grille) {
}

std::unordered_map<Coordinates, std::optional<Box> > GrilleVM::get_cases() const {
    return grille_.get_cases();
}

unsigned int GrilleVM::get_height() const {
    return grille_.get_height();
}

unsigned int GrilleVM::get_width() const {
    return grille_.get_width();
}

