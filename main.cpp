#include "Model/Game.h"
#include "Vue/ConsoleVue.h"

int main() {
    Game g;

    GameVM game_vm(g);
    g.register_observer(&game_vm);

    ConsoleVue vue(game_vm);
    game_vm.register_observer(&vue);

    vue.run();
}