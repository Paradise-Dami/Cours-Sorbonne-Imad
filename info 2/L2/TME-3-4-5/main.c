#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h" // contient charger_n_entrees
#include "biblioLC.h"       // contient les définitions de Biblio et afficher_biblio
#include <string.h>

void affiche_livre(Livre *livre)
{
    printf("Num : %d, Titre : %s, Auteur: %s\n", livre->num, livre->titre, livre->auteur);
}

void affiche_biblio(Biblio *b)
{
    Livre *actuel = b->L;
    while (actuel != NULL)
    {
        affiche_livre(actuel);
        actuel = actuel->suiv;
    }
}

Livre *recherche_livre(int num, Biblio *b)
{
    Livre *actuel = b->L;
    while ((actuel->num != num) && (actuel != NULL))
    {
        actuel = actuel->suiv;
    }
    if (actuel == NULL)
    {
        printf("Erreur, le livre de num %d n'existe pas", num);
        return NULL;
    }
    else
    {
        affiche_livre(actuel);
        return actuel;
    }
}

Biblio *recherche_auteur(char *auteur, Biblio *b)
{
    Livre *actuel = b->L;
    Biblio *bibli_out = creer_biblio();
    while (actuel != NULL)
    {
        if (actuel->auteur == auteur)
        {
            inserer_en_tete(bibli_out, actuel->num, actuel->titre,
                            actuel->auteur);
        }
        actuel = actuel->suiv;
    }
    return bibli_out;
}

void supp_livre(Biblio *b, int num, char *auteur, char *titre)
{
    Livre *prec = NULL;
    Livre *actuel = b->L;
    if (actuel == NULL)
    {
        return;
    }
    while (actuel->suiv != NULL)
    {
        if ((actuel->suiv->num = num) && (actuel->suiv->auteur = auteur) && (actuel->suiv->titre = titre))
        {
            Livre *temp = actuel->suiv;
            actuel->suiv = actuel->suiv->suiv;
            liberer_livre(temp);
        }
        actuel = actuel->suiv;
    }
}

void fusion_bibli(Biblio *b1, Biblio *b2)
{
    Livre *actuel = b2->L;
    while (actuel != NULL)
    {
        inserer_en_tete(b1, actuel->num, actuel->titre, actuel->auteur);
        actuel = actuel->suiv;
    }
    liberer_biblio(b2);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }
    char *nomfic = argv[1];
    int n = atoi(argv[2]);
    Biblio *b = charger_n_entrees(nomfic, n);
    affiche_biblio(b);
    printf("Bibliothèque chargée avec succès (%d entrées) :\n", n);
    liberer_biblio(b);
    return 0;
}