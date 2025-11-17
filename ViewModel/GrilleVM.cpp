//
// Created by sacha on 17/11/2025.
//

#include "GrilleVM.h"

std::unordered_map<Coordinates, std::optional<CaseVM> > GrilleVM::get_cases() {
    std::unordered_map<Coordinates, std::optional<CaseVM> > grille{};
    for (const auto &kv: grille_.get_cases()) {
        if (kv.second.has_value()) {
            CaseVM cvm(kv.second.value());
            grille.emplace(kv.first, cvm);
        } else {
            std::optional<CaseVM> empty;
            grille.emplace(kv.first, empty);
        }
    }

    return grille;
}
