#include <stdio.h>

//question 1
int jours(int nbConta, int popTotale, float etreInfecte) {
    int joursPasses = 0;
    int nbInfecte = 1;
    float seuil = (etreInfecte/100.0) * popTotale;

    while (nbInfecte <= seuil) {
        joursPasses++;
        nbInfecte = nbInfecte + nbInfecte * nbConta;
        }
        
    return joursPasses;
}

//question 2

float pourcentage(int x, int population, int jours_etudies) {
    int contamines = 1;
    
    for (int i = 0; i < jours_etudies; i++) {
        contamines += contamines * x;
        if (contamines >= population) {
            return 100.0; // On ne peut pas dépasser 100% de la population
        }
    }
    
    return (contamines * 100.0) / population;
}

int main() {
    printf("%d\n",jours(5,10000,100.00));
    printf("%d\n",jours(5,10000,50.00));
    printf("%d\n",jours(5,10000,25.00));
    printf("%d\n",jours(5,10000,10.00));
    printf("%d\n",jours(5,10000,0.06));
    printf("%f\n",pourcentage(5,10000,2));
    return 0;
}