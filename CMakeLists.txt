cmake_minimum_required(VERSION 4.0)
project(TD2)

set(CMAKE_CXX_STANDARD 20)

add_executable(TD2 main.cpp
        Model/Direction.h
        Model/Case.cpp
        Model/Case.h
        Model/Grille.cpp
        Model/Grille.h
        Model/Coordinates.cpp
        Model/Coordinates.h
        Vue/IVue.cpp
        Vue/IVue.h
        Vue/ConsoleVue.cpp
        Vue/ConsoleVue.h
        Model/Game.cpp
        Model/Game.h
        ViewModel/GameVM.cpp
        ViewModel/GameVM.h
        Vue/Game/ConsoleGame.cpp
        Vue/Game/ConsoleGame.h
        Vue/Game/ConsoleGrille.cpp
        Vue/Game/ConsoleGrille.h
        ViewModel/GrilleVM.cpp
        ViewModel/GrilleVM.h
        Model/GameState.h
)
