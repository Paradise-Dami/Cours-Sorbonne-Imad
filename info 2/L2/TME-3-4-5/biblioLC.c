#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

Livre *creer_livre(int num, char *titre, char *auteur)
{
    Livre *livre = malloc(sizeof(Livre));
    if (!livre) return NULL;

    livre->num = num;
    livre->titre = strdup(titre);
    livre->auteur = strdup(auteur);
    livre->suiv = NULL;
    return livre;
}


void liberer_livre(Livre *l)
{
    free(l->titre);
    free(l->auteur);
    free(l);
}

Biblio *creer_biblio()
{
    Biblio *bibli = (Biblio *)malloc(sizeof(Biblio));
    bibli->L = NULL;
    return bibli;
}

void liberer_bibli(Biblio *b)
{
    Livre *actuel = b->L;
    while (actuel != NULL)
    {
        Livre *suivant = actuel->suiv;
        free(actuel);
        actuel = suivant;
    }
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur)
{
    Livre *l = creer_livre(num, titre, auteur);
    if (b->L == NULL)
    {
        b->L = l;
    }
    else
    {
        l->suiv = b->L;
        b->L = l;
    }
}

