//
// Created by sacha on 17/11/2025.
//

#include "Case.h"

Case::Case(long v) {
    value_ = v;
}

long Case::get_value() const {
    return value_;
}

std::optional<Case> Case::combine(Case c) const {
    if (c.get_value() == value_) {
        Case new_case(value_ * 2);
        return new_case;
    }
}
