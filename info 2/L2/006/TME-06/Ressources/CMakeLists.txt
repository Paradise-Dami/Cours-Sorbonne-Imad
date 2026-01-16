cmake_minimum_required(VERSION 4.0)
project(Ressources C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ressources
        ArbreQuat.h
        Chaine.c
        Chaine.h
        ChaineMain.c
        Hachage.h
        Reseau.h
        SVGwriter.c
        SVGwriter.h
        Reseau.c)
