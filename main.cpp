#include <iostream>

#include "Model/Direction.h"
#include "Model/Game.h"
#include "Model/Grille.h"
#include "Vue/ConsoleVue.h"

int main() {

    Game g;

    const GameVM game_vm(g);

    ConsoleVue vue(game_vm);

    vue.Display();

    vue.move(Direction::Left);
    vue.Display();
    return 0;
}
