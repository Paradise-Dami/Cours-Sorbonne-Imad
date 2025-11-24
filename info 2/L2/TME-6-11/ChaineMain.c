#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chaine.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <fichier.cha>\n", argv[0]);
        return 1;
    }

    char *nomFichier = argv[1];
    
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL)
    {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", nomFichier);
        return 1;
    }

    printf("=== Lecture du fichier %s ===\n", nomFichier);
    
    Chaines *chaines = lectureChaines(f);
    fclose(f);

    if (chaines == NULL)
    {
        printf("Erreur lors de la lecture des chaînes\n");
        return 1;
    }

    printf("Nombre de chaînes: %d\n", chaines->nbChaines);
    printf("Gamma: %d\n\n", chaines->gamma);

    char nomFichierOut[256];
    snprintf(nomFichierOut, sizeof(nomFichierOut), "output_%s", nomFichier);
    
    FILE *fileOut = fopen(nomFichierOut, "w");
    if (fileOut != NULL)
    {
        printf("=== Écriture dans %s ===\n", nomFichierOut);
        ecrireChaines(chaines, fileOut);
        fclose(fileOut);
        printf("Fichier créé avec succès!\n\n");
    }

    double longueur = longueurTotale(chaines);
    printf("=== Statistiques ===\n");
    printf("Longueur totale des chaînes: %.2lf\n", longueur);

    int nbPoints = comptePointsTotal(chaines);
    printf("Nombre total de points: %d\n\n", nbPoints);

    printf("Génération du fichier SVG\n");
    char nomInstance[256];
    strcpy(nomInstance, nomFichier);
    char *dot = strrchr(nomInstance, '.');
    if (dot != NULL) *dot = '\0';
    
    afficheChainesSVG(chaines, nomInstance);
    printf("Fichier SVG créé: %s.html\n\n", nomInstance);

    freeChaines(chaines);
    printf("=== Mémoire libérée ===\n");

    return 0;
}