//
// Created by sacha on 29/11/2025.
//

#include "ConsoleGrille.h"

#include <ostream>
#include <cfloat>
#include <complex>
#include <random>
#include <ranges>
ConsoleGrille::ConsoleGrille(GrilleVM grille) : grille_(std::move(grille)) {
}


std::ostream & operator<<(std::ostream &os, const ConsoleGrille &g) {
    for (int i = 0; i < g.grille_.get_height(); i++) {
        for (int j = 0; j < g.grille_.get_width(); j++) {
            Coordinates coordinates(j, i);

            if (std::optional<Box> c = g.grille_.get_cases().at(coordinates); c.has_value()) {
                os << std::to_string(static_cast<int>(round(pow(2, c.value().get_value()))));
            } else {
                os << "#";
            }
            os << "\t";
        }
        os << std::endl;
    }
    return os;
}
