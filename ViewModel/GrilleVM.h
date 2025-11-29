//
// Created by sacha on 29/11/2025.
//

#ifndef TD2_GRILLEVM_H
#define TD2_GRILLEVM_H

#include "../Model/Grille.h"

class GrilleVM {
    Grille grille_;

public:
    GrilleVM(Grille grille);
    
    unsigned int get_width() const;
    unsigned int get_height() const;
    std::unordered_map<Coordinates, std::optional<Case>> get_cases() const;
};


#endif //TD2_GRILLEVM_H