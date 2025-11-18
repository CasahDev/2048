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
        ViewModel/GrilleVM.cpp
        ViewModel/GrilleVM.h
        ViewModel/CaseVM.cpp
        ViewModel/CaseVM.h
        Vue/IVue.cpp
        Vue/IVue.h
        Vue/ConsoleVue.cpp
        Vue/ConsoleVue.h
)
