#include "Chaine.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE_LENGTH 256

Chaine *lectureChaine(File *f){
    int j = 1;
    int nb_chaines, gamma; 
    char ligne[MAX_SIZE_LENGTH];
    Chaine *c = (Chaine *)malloc(sizeof(Chaine));
    
    if (f==NULL){
        printf("Erreur, fichier non accessible");
        return NULL;
    }

    while (fgets(ligne, MAX_SIZE_LENGTH, f) and (i < 3)){
        
    }

    while ((fgets(ligne, MAX_SIZE_LENGTH, f) != NULL) and () ){
        
        int num_chaine, nb_noeuds;
        char liste_chaine[253];
        double x, y;
        int i = 0;


        sscanf(ligne, "%d %d %[^\n]",num_chaine, nb_noeuds, liste_chaine);
        
        while ((sscanf(liste_chaine, "%f %f %[^\n]", x, y, liste_chaine)) != (i < nb_noeuds)){

        }
    }

}