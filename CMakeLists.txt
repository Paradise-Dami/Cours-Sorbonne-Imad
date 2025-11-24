cmake_minimum_required(VERSION 4.0)
project(Cours_Sorbonne_Imad C)

set(CMAKE_C_STANDARD 11)

include_directories("info 2/L2/006/TME-06/Ressources/Ressources")
include_directories("info 2/L2/TME-3-4-5")
include_directories("info 2/tme/semaine8")
include_directories("info 2/tme/semaine9-10")

add_executable(Cours_Sorbonne_Imad
        "info 2/L2/006/TME-06/Ressources/Ressources/ArbreQuat.h"
        "info 2/L2/006/TME-06/Ressources/Ressources/Chaine.h"
        "info 2/L2/006/TME-06/Ressources/Ressources/Hachage.h"
        "info 2/L2/006/TME-06/Ressources/Ressources/Reseau.h"
        "info 2/L2/006/TME-06/Ressources/Ressources/SVGwriter.c"
        "info 2/L2/006/TME-06/Ressources/Ressources/SVGwriter.h"
        "info 2/L2/code_exercice1/tme1_exo1p1.c"
        "info 2/L2/code_exercice1/tme1_exo1p2.c"
        "info 2/L2/code_exercice1/tme1_exo1p3.c"
        "info 2/L2/TME-3-4-5/biblioLC.c"
        "info 2/L2/TME-3-4-5/biblioLC.h"
        "info 2/L2/TME-3-4-5/entreeSortieLC.c"
        "info 2/L2/TME-3-4-5/entreeSortieLC.h"
        "info 2/L2/TME-3-4-5/main.c"
        "info 2/L2/exercice2.c"
        "info 2/td/td_semaine_2.c"
        "info 2/tme/semaine1/Exercice 5.c"
        "info 2/tme/semaine1/Exercice 7.c"
        "info 2/tme/semaine1/Exercice 8.c"
        "info 2/tme/semaine1/hello.c"
        "info 2/tme/semaine1/jeuTest.c"
        "info 2/tme/semaine2/exemple_graphique.c"
        "info 2/tme/semaine2/Exercice 11.c"
        "info 2/tme/semaine2/Exercice 14.c"
        "info 2/tme/semaine2/Exercice11.c"
        "info 2/tme/semaine3/Exercice 16.c"
        "info 2/tme/semaine3/Exercice 17.c"
        "info 2/tme/semaine3/Exercice 18.c"
        "info 2/tme/semaine3/Exercice 19.c"
        "info 2/tme/semaine3/Exercice 20.c"
        "info 2/tme/semaine3/min_max_moy.c"
        "info 2/tme/semaine3/pnz.c"
        "info 2/tme/semaine4/Exercice 23.c"
        "info 2/tme/semaine4/Exercice 24.c"
        "info 2/tme/semaine4/Exercice 26.c"
        "info 2/tme/semaine5/Exercice 27.c"
        "info 2/tme/semaine5/Exercice 28.c"
        "info 2/tme/semaine5/Exercice 30.c"
        "info 2/tme/semaine5/Exercice 32.c"
        "info 2/tme/semaine6/Exercice 32.c"
        "info 2/tme/semaine7/planetes.c"
        "info 2/tme/semaine7/Tetris1.c"
        "info 2/tme/semaine8/liste_entiers.c"
        "info 2/tme/semaine8/liste_entiers.h"
        "info 2/tme/semaine8/test_liste.c"
        "info 2/tme/semaine9-10/multi_ensembles.c"
        "info 2/tme/semaine9-10/multi_ensembles.h"
        "info 2/tme/semaine9-10/test_multi_ensembles.c"
        "info 2/tme/test/test.c")
