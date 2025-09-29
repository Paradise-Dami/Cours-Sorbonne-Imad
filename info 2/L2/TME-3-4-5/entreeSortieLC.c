#include <biblioLC.h>
#include <stdio.h>
#include <stdlib.h>

Biblio *charger_n_entrees(char *nomfic, int n)
{   
    char *ligne[256];
    char *auteur[256];
    char *nom[256];
    
    FILE *fichier = fopen(nomfic, "r");
    if (fichier == NULL)
    {
        printf("erreur fichier introuvable");
        return NULL;
    }

    int i = 0;
    
    while ((fgets(ligne, 256, fichier) != NULL) && (i < n)){ // je pourrais utiliser les id dans les lignes...
        i++;

    }
}

void enregistrer_biblio(Biblio *b, char *nomfic) {}