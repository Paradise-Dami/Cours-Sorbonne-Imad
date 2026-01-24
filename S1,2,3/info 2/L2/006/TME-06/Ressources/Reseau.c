#include "Reseau.h"

#include <stdio.h>
#include <stdlib.h>

#include "Chaine.h"


void ajouteVoisin(Noeud *noeud, Noeud *voisin)
{
    if (noeud == NULL || voisin == NULL) return;

    // Vérifier si le voisin existe déjà
    CellNoeud *current = noeud->voisins;
    while (current != NULL)
    {
        if (current->nd == voisin) return;  // Déjà présent
        current = current->suiv;
    }

    // Ajouter le voisin en tête de liste
    CellNoeud *nouvelleCellule = (CellNoeud *)malloc(sizeof(CellNoeud));
    if (nouvelleCellule == NULL)
    {
        printf("Erreur allocation CellNoeud pour voisin\n");
        return;
    }

    nouvelleCellule->nd = voisin;
    nouvelleCellule->suiv = noeud->voisins;
    noeud->voisins = nouvelleCellule;
}

Reseau *reconstitueReseauListe(Chaines *C) {
    if (C==NULL) return NULL;
    Reseau *R = (Reseau *)malloc(sizeof(Reseau));
    if (R==NULL) return NULL;
    R->gamma = C->gamma;
    R->nbNoeuds = 0;
    CellCommodite *lastCommodite = NULL;

    CellChaine *currentChain = C->chaines;
    CellNoeud *lastCellNoeud = NULL;
    Noeud *lastNode = NULL;
    while (currentChain!=NULL) {
        //ajouter le premier point de la chaine
        CellPoint *currentPoint = currentChain->points;
        Noeud *NewNode = rechercheCreeNoeudListe(R,currentPoint->x,currentPoint->y);
        lastNode = NewNode;
        CellNoeud *InitCellNode = (CellNoeud *)malloc(sizeof(CellNoeud));
        InitCellNode->nd = NewNode;
        InitCellNode->suiv = lastCellNoeud;
        lastCellNoeud = InitCellNode;
        currentPoint = currentPoint->suiv;
        CellCommodite *commodite = (CellCommodite *)malloc(sizeof(CellCommodite));
        commodite->extrA = NewNode;
        currentPoint = currentPoint->suiv;
        R->nbNoeuds = R->nbNoeuds + 1;
        while (currentPoint!=NULL) {
            NewNode = rechercheCreeNoeudListe(R,currentPoint->x,currentPoint->y);
            CellNoeud *NewCellNode = (CellNoeud *)malloc(sizeof(CellNoeud));
            NewCellNode->nd = NewNode;
            NewCellNode->suiv = lastCellNoeud;
            lastCellNoeud = NewCellNode;
            if (lastCellNoeud != NULL) {
                ajouteVoisin(NewNode, lastNode);
                ajouteVoisin(lastNode, NewNode);
            }
            currentPoint = currentPoint->suiv;
            R->nbNoeuds = R->nbNoeuds + 1;
        }
        commodite->extrB = NewNode;
        commodite->suiv = lastCommodite;
        lastCommodite = commodite;
        currentChain = currentChain->suiv;
    }
    return R;
}


void AssocierVoisins(Noeud *noeud, CellNoeud *precNoeud, CellNoeud *suivNoeud) {
    if (noeud==NULL) return;
    CellNoeud *voisinActuel = noeud->voisins;
    if (voisinActuel == NULL) { //si noeud n'a pas de voisins
        voisinActuel = precNoeud;
        voisinActuel->suiv = suivNoeud;
    } else {
        while (voisinActuel!=NULL) {
            voisinActuel = voisinActuel->suiv;
        }
        voisinActuel = precNoeud;
        if (voisinActuel==NULL) {
            voisinActuel = suivNoeud;
        } else {
            voisinActuel->suiv = suivNoeud;
        }
    }
}


Noeud *rechercheCreeNoeudListe(Reseau *R, double x, double y)
{
    if (R==NULL) {
        return NULL;
    }
    CellNoeud *NoeudActuel = R->noeuds;
    int numNoeud = R->noeuds->nd->num;
    while (NoeudActuel!=NULL) {
        if ((NoeudActuel->nd->x == x) && (NoeudActuel->nd->y == y)) {
            return NoeudActuel->nd;
        }
        numNoeud = NoeudActuel->nd->num;
        NoeudActuel = NoeudActuel->suiv;
    }
    // ajouter le noeud sinon
    Noeud *NouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    if (NouveauNoeud == NULL) {
        return NULL;
    }
    NouveauNoeud->x = x;
    NouveauNoeud->y = y;
    NouveauNoeud->num = numNoeud + 1;

    CellNoeud *NouvelleCell = (CellNoeud *)malloc(sizeof(CellNoeud));
    if (NouvelleCell == NULL) {
        return NULL;
    }
    NouvelleCell->nd = NouveauNoeud;
    NouvelleCell->suiv = R->noeuds;
    R->noeuds = NouvelleCell;
    return NouveauNoeud;
}

void freeReseau(Reseau *R)
{
    if (R == NULL) return;

    // Libérer les nœuds
    CellNoeud *currentNoeud = R->noeuds;
    while (currentNoeud != NULL)
    {
        CellNoeud *nextNoeud = currentNoeud->suiv;

        // Libérer la liste des voisins du nœud
        CellNoeud *currentVoisin = currentNoeud->nd->voisins;
        while (currentVoisin != NULL)
        {
            CellNoeud *nextVoisin = currentVoisin->suiv;
            free(currentVoisin);
            currentVoisin = nextVoisin;
        }

        // Libérer le nœud lui-même
        free(currentNoeud->nd);
        free(currentNoeud);
        currentNoeud = nextNoeud;
    }

    // Libérer les commodités
    CellCommodite *currentCommodite = R->commodites;
    while (currentCommodite != NULL)
    {
        CellCommodite *nextCommodite = currentCommodite->suiv;
        free(currentCommodite);
        currentCommodite = nextCommodite;
    }

    // Libérer le réseau
    free(R);
}