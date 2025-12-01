//
// Created by sacha on 17/11/2025.
//

#include "Box.h"

Box::Box(const unsigned long v) {
    value_ = v;
}

unsigned long Box::get_value() const {
    return value_;
}

std::optional<Box> Box::combine(const Box c) const {
    if (c.get_value() == value_) {
        Box new_case(value_ + 1);
        return new_case;
    }

    constexpr std::optional<Box> empty;
    return empty;
}

