//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_CASE_H
#define TD2_CASE_H

#pragma once

#include <optional>


class Case {
    long value_;

public:
    explicit Case(long v);
    [[nodiscard]] long get_value() const;
    [[nodiscard]] std::optional<Case> combine(Case c) const;
};


#endif //TD2_CASE_H