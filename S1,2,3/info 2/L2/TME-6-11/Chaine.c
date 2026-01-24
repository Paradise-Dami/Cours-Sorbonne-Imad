#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Chaine.h"
#include "SVGwriter.h"
#define MAX_LENGTH 256

// Q 1.1 - Lecture des chaînes
Chaines *lectureChaines(FILE *f)
{
    int NbChain;
    int Gamma;
    char line[MAX_LENGTH];
    char mot[128];

    if (f == NULL)
    {
        printf("Fichier Inaccessible\n");
        return NULL;
    }

    fgets(line, MAX_LENGTH, f);
    sscanf(line, "%s %d", mot, &NbChain);
    fgets(line, MAX_LENGTH, f);
    sscanf(line, "%s %d", mot, &Gamma);

    CellChaine *CellChainSuiv = NULL;

    while (fgets(line, MAX_LENGTH, f) != NULL)
    {
        // Allouer une NOUVELLE CellChaine à chaque tour
        CellChaine *CellChain = (CellChaine *)malloc(sizeof(CellChaine));
        if (CellChain == NULL)
        {
            printf("Erreur allocation CellChaine\n");
            return NULL;
        }

        int ChainNumber;
        int PointNumber;
        char PointList[MAX_LENGTH];

        sscanf(line, "%d %d %[^\n]", &ChainNumber, &PointNumber, PointList);

        CellPoint *PointSuiv = NULL;
        char *ptr = PointList;
        int decale;

        for (int i = 0; i < PointNumber; i++)
        {
            CellPoint *Point = (CellPoint *)malloc(sizeof(CellPoint));
            if (Point == NULL)
            {
                printf("Erreur allocation CellPoint\n");
                return NULL;
            }

            sscanf(ptr, "%lf %lf%n", &(Point->x), &(Point->y), &decale);
            ptr = ptr + decale;

            Point->suiv = PointSuiv;
            PointSuiv = Point;
        }

        CellChain->numero = ChainNumber;
        CellChain->points = PointSuiv;
        CellChain->suiv = CellChainSuiv;
        CellChainSuiv = CellChain;
    }

    Chaines *FinalChain = (Chaines *)malloc(sizeof(Chaines));
    if (FinalChain == NULL)
    {
        printf("Erreur d'allocation de Chaines\n");
        return NULL;
    }

    FinalChain->gamma = Gamma;
    FinalChain->nbChaines = NbChain;
    FinalChain->chaines = CellChainSuiv;

    return FinalChain;
}

int comptePoints(CellPoint *points)
{
    int count = 0;
    CellPoint *current = points;
    while (current != NULL)
    {
        count++;
        current = current->suiv;
    }
    return count;
}


void ecrireChaines(Chaines *C, FILE *f)
{
    if (C == NULL || f == NULL)
    {
        printf("Erreur de lecture des données");
        return;
    }

    fprintf(f, "NbChain: %d\n", C->nbChaines);
    fprintf(f, "Gamma: %d\n", C->gamma);
    fprintf(f, "\n");

    CellChaine *currentChain = C->chaines;
    while (currentChain != NULL)
    {
        fprintf(f, "%d %d", currentChain->numero, comptePoints(currentChain->points));

        CellPoint *currentPoint = currentChain->points;
        while (currentPoint != NULL)
        {
            fprintf(f, " %.2lf %.2lf", currentPoint->x, currentPoint->y);
            currentPoint = currentPoint->suiv;
        }
        fprintf(f, "\n");

        currentChain = currentChain->suiv;
    }
}


double longueurChaine(CellChaine *c)
{
    if (c == NULL || c->points == NULL)
        return 0.0;

    double longueur = 0.0;
    CellPoint *current = c->points;

    while (current != NULL && current->suiv != NULL)
    {
        double dx = current->suiv->x - current->x;
        double dy = current->suiv->y - current->y;
        longueur += sqrt(dx * dx + dy * dy);
        current = current->suiv;
    }

    return longueur;
}

double longueurTotale(Chaines *C)
{
    if (C == NULL)
        return 0.0;

    double longueurTot = 0.0;
    CellChaine *current = C->chaines;

    while (current != NULL)
    {
        longueurTot += longueurChaine(current);
        current = current->suiv;
    }

    return longueurTot;
}


int comptePointsTotal(Chaines *C)
{
    if (C == NULL)
        return 0;

    int total = 0;
    CellChaine *currentChain = C->chaines;

    while (currentChain != NULL)
    {
        CellPoint *currentPoint = currentChain->points;
        while (currentPoint != NULL)
        {
            total++;
            currentPoint = currentPoint->suiv;
        }
        currentChain = currentChain->suiv;
    }

    return total;
}

void freeChaines(Chaines *chaines)
{
    if (chaines == NULL)
        return;

    CellChaine *currentChain = chaines->chaines;
    while (currentChain != NULL)
    {
        CellChaine *nextChain = currentChain->suiv;

        // Libérer tous les points de cette chaîne
        CellPoint *currentPoint = currentChain->points;
        while (currentPoint != NULL)
        {
            CellPoint *nextPoint = currentPoint->suiv;
            free(currentPoint);
            currentPoint = nextPoint;
        }

        free(currentChain);
        currentChain = nextChain;
    }

    free(chaines);
}

void afficheChainesSVG(Chaines *C, char* nomInstance){
    int i;
    double maxx=0,maxy=0,minx=1e6,miny=1e6;
    CellChaine *ccour;
    CellPoint *pcour;
    double precx,precy;
    SVGwriter svg;
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        while (pcour!=NULL){
            if (maxx<pcour->x) maxx=pcour->x;
            if (maxy<pcour->y) maxy=pcour->y;
            if (minx>pcour->x) minx=pcour->x;
            if (miny>pcour->y) miny=pcour->y;  
            pcour=pcour->suiv;
        }
    ccour=ccour->suiv;
    }
    SVGinit(&svg,nomInstance,500,500);
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        SVGlineRandColor(&svg);
        SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny)); 
        precx=pcour->x;
        precy=pcour->y;  
        pcour=pcour->suiv;
        while (pcour!=NULL){
            SVGline(&svg,500*(precx-minx)/(maxx-minx),500*(precy-miny)/(maxy-miny),500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            precx=pcour->x;
            precy=pcour->y;    
            pcour=pcour->suiv;
        }
        ccour=ccour->suiv;
    }
    SVGfinalize(&svg);
}
