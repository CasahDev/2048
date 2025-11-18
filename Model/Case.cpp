//
// Created by sacha on 17/11/2025.
//

#include "Case.h"

Case::Case(const long v) {
    value_ = v;
}

long Case::get_value() const {
    return value_;
}

std::optional<Case> Case::combine(const Case c) const {
    if (c.get_value() == value_) {
        Case new_case(value_ * 2);
        return new_case;
    }

    constexpr std::optional<Case> empty;
    return empty;
}
