//
// Created by sacha on 17/11/2025.
//

#include "IVue.h"

[[noreturn]] void IVue::run() {
    display();

    while (true) {
        read_input();
    }
}
