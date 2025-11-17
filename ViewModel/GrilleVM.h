//
// Created by sacha on 17/11/2025.
//

#ifndef TD2_GRILLEVM_H
#define TD2_GRILLEVM_H

#include "CaseVM.h"
#include "../Model/Grille.h"

class GrilleVM {
    Grille grille_;

public:
    GrilleVM(Grille grille);

    std::unordered_map<Coordinates, std::optional<CaseVM>> get_cases();
};


#endif //TD2_GRILLEVM_H