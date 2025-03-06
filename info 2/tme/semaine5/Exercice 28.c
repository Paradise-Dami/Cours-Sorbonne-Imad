#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_AMIS 4
#define NB_JOURS 7

//question 1

void setuptab(float tab[][NB_AMIS]) {
    for (int i = 0; i < NB_JOURS; i++) {
        for (int j = 0; j < NB_AMIS; j++) {
            tab[i][j] = 0;
        }
    }
}


void comptes(float tab[][NB_AMIS]) {
    for (int i = 0; i < NB_JOURS; i++) {
        float soldejour = rand()%(50-30+1) + 30; //alors c'est pas un tirage uniforme de cette manière
        int ami = rand()%NB_AMIS;
        for (int j = 0; j < NB_AMIS; j++) {
            if (ami == j) {
                tab[i][j] = soldejour;
            } else {
                tab[i][j] = -soldejour/(NB_AMIS);
            }
        }
    }
}


float soldetotal(float tab[][NB_AMIS], int individu) {
    int solde = 0;
    for (int i = 0; i < NB_JOURS; i++) {
        solde = solde + tab[i][individu];
    }
    return solde;
}

int main() {
    srand(time(NULL));
    float tab[NB_JOURS][NB_AMIS];
    setuptab(tab);
    comptes(tab);
    for (int i = 0; i < NB_JOURS; i++) {
        for (int j = 0; j < NB_AMIS; j++) {
            printf("%0.2f ",tab[i][j]);
    }
    }
    printf("\n%f\n",soldetotal(tab,1));   
    return 0;
}