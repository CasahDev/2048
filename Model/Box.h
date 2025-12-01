//
// Created by sacha on 17/11/2025.
//

#pragma once

#include <optional>


class Box {
    unsigned long value_;

public:
    explicit Box(unsigned long v);
    [[nodiscard]] unsigned long get_value() const;
    [[nodiscard]] std::optional<Box> combine(Box c) const;
};