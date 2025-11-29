//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <cstddef>
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


namespace std {
    template<>
    struct hash<Coordinates> {
        std::size_t operator()(Coordinates const &c) const noexcept {
            return (static_cast<std::size_t>(c.get_x()) * 31u) ^ static_cast<std::size_t>(c.get_y());
        }
    };
}
