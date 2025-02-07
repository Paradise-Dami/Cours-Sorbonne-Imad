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

float pourcentage(int nbConta, int popTotale, int nbJours) {
    int i;
    for (i=0;i<=popTotale;i++) {
        printf("%d,%f\n",jours(nbConta,popTotale,i/100.0),i/100.0);
        if (jours(nbConta,popTotale,i/100.0)==nbJours) {
            return i/100.0;
        }
    }
    return -1.0;

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