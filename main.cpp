#include <iostream>

#include "Model/Game.h"
#include "Vue/ConsoleVue.h"
#include <unistd.h>     // STDIN_FILENO
#include <termios.h>    // struct termios, tcgetattr, tcsetattr, etc.
#include <stdio.h>

int main() {

    Game g;

    const GameVM game_vm(g);

    ConsoleVue vue(game_vm);

    vue.display();
    bool lost = false;

    termios t{};

    if (tcgetattr(STDIN_FILENO, &t) == -1) {
        perror("tcgetattr");
        return -1;
    }

    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &t) == -1) {
        perror("tcsetattr");
    }

    while (!lost) {
        char key = 0;
        if (read(STDIN_FILENO, &key, 1) == 1) {
            std::optional<Direction> direction;

            switch (key) {
                case 'z':
                    direction = Direction::Up;
                    break;
                case 'q':
                    direction = Direction::Left;
                    break;
                case 's':
                    direction = Direction::Down;
                    break;
                case 'd':
                    direction = Direction::Right;
                    break;
            }

            if (direction.has_value()) {
                vue.move(direction.value());

                vue.display();

                lost = vue.check_for_loose();
            }
        }
    }

    vue.display_lost();

    return 0;
}
