//
// Created by sacha on 29/11/2025.
//

#ifndef TD2_CONSOLEGRILLE_H
#define TD2_CONSOLEGRILLE_H

#include "../../Model/Grille.h"
#include "../../ViewModel/GrilleVM.h"

class ConsoleGrille {
    GrilleVM grille_;

public:
    explicit ConsoleGrille(GrilleVM grille);

    friend std::ostream& operator<<(std::ostream &os, const ConsoleGrille& g);
};


#endif //TD2_CONSOLEGRILLE_H