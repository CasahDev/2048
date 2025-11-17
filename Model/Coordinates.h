//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_COORDINATES_H
#define TD2_COORDINATES_H

#pragma once

#include <functional>


class Coordinates {
    int x_;
    int y_;

public:
    Coordinates(int x, int y);

    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;

    bool operator==(const Coordinates &c) const {
        return x_ == c.get_x() && y_ == c.get_y();
    }
};

namespace std {
    template<>
    struct hash<Coordinates> {
        std::size_t operator()(Coordinates const& c) const noexcept {
            // combinaison simple et sans état, donc copy-constructible
            // 31 est un petit mix; on peut remplacer par un meilleur mix si besoin
            return (static_cast<std::size_t>(c.get_x()) * 31u) ^ static_cast<std::size_t>(c.get_y());
        }
    };
}

#endif //TD2_COORDINATES_H