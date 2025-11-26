//
// Created by sacha on 17/11/2025.
//

#include "Coordinates.h"

Coordinates::Coordinates(int x, int y) : x_(x), y_(y) {
}

int Coordinates::get_x() const {
    return x_;
}

int Coordinates::get_y() const {
    return y_;
}

bool Coordinates::operator==(const Coordinates &c) const {
    return x_ == c.get_x() && y_ == c.get_y();
}

template<>
struct std::hash<Coordinates> {
    std::size_t operator()(Coordinates const& c) const noexcept {
        return (static_cast<std::size_t>(c.get_x()) * 31u) ^ static_cast<std::size_t>(c.get_y());
    }
};
