//
// Created by sacha on 18/11/2025.
//

#ifndef TD2_CONSOLEVUE_H
#define TD2_CONSOLEVUE_H
#include "IVue.h"
#include "../ViewModel/GrilleVM.h"


class ConsoleVue : IVue {
private:
    GrilleVM grille;

public:
    ConsoleVue();
    void move(Direction direction) override;

    void Display() override;
};


#endif //TD2_CONSOLEVUE_H