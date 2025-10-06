#include "entreeSortieLC.h"
#include <stdio.h>
#include <stdlib.h>

Biblio *charger_n_entrees(char *nomfic, int n)
{
    char ligne[512];
    char auteur[256];
    char nom[256];
    int id;
    Biblio *b = creer_biblio();

    FILE *fichier = fopen(nomfic, "r");
    if (fichier == NULL)
    {
        printf("erreur fichier introuvable");
        return NULL;
    }

    int i = 0;

    while ((fgets(ligne, sizeof(ligne), fichier) != NULL) && (i < n))
    { // je pourrais utiliser les id dans les lignes...
        sscanf(ligne, "%d %s %s", &id, nom, auteur);
        i++;
        inserer_en_tete(b, id, nom, auteur);
    }
    fclose(fichier);
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic)
{
    FILE *fichier = fopen(nomfic, "w");
    if (fichier == NULL)
    {
        printf("erreur fichier introuvable");
    }
    Livre *actuel = b->L;
    while (actuel != NULL)
    {
        fprintf(fichier, "%d %s %s", actuel->num, actuel->titre, actuel->auteur);
        fputc('\n', fichier);
        actuel = actuel->suiv;
    }
    fclose(fichier);
}