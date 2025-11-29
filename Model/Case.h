//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <optional>


class Case {
    unsigned long value_;

public:
    explicit Case(unsigned long v);
    [[nodiscard]] unsigned long get_value() const;
    [[nodiscard]] std::optional<Case> combine(Case c) const;
};