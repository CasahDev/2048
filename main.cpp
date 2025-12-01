#include <iostream>

#include "Model/Game.h"
#include "Vue/ConsoleVue.h"
#include <unistd.h>     // STDIN_FILENO
#include <termios.h>    // struct termios, tcgetattr, tcsetattr, etc.
#include <stdio.h>

#include "Model/GameState.h"

int main() {

    Game g;

    const GameVM game_vm(g);

    ConsoleVue vue(game_vm);
    
    vue.run();
}