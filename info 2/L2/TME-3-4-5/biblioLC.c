#include <biblioLC.h>
#include <stdio.h>
#include <stdlib.h>

Livre *creer_livre(int num, char *titre, char *auteur)
{
    Livre *livre = (Livre *)malloc(sizeof(Livre));
    livre->num = num;
    livre->titre = (char *)malloc(sizeof(char));
    livre->titre = strncpy(titre);
    livre->auteur = (char *)malloc(sizeof(char));
    livre->auteur = strncpy(auteur);
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

void liberer_biblio(Biblio *b)
{
    Livre *actuel = b;
    while (actuel != NULL)
    {
        Livre *suivant = actuel->suiv;
        free(actuel->suiv);
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

