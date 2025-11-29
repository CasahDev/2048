//
// Created by sacha on 29/11/2025.
//

#ifndef TD2_GAMEVUE_H
#define TD2_GAMEVUE_H
#include "../../ViewModel/GameVM.h"


class ConsoleGame {
    GameVM game_;

public:
    explicit ConsoleGame(GameVM game);
    friend std::ostream& operator<<(std::ostream &os, ConsoleGame &g);
};


#endif //TD2_GAMEVUE_H