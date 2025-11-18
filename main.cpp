#include <iostream>

#include "Model/Direction.h"
#include "Model/Grille.h"

int main() {

    Grille g(5, 5);

    std::cout << g << std::endl;

    g.swipe(Direction::Right);

    std::cout << g << std::endl;

    return 0;
}
