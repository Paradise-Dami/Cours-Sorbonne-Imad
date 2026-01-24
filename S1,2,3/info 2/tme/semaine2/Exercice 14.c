#include <stdio.h>
#define TADULTE 22.7
#define TENFANT 10.75
#define TFAMILLE 57.80

float prixEntree2(int nbAdultes, int nbEnfants) {
    float prixFinal = 0;
    prixFinal = nbAdultes*TADULTE + nbEnfants*TENFANT;
    float prixFinalTarifFamille;
    if (nbAdultes > 2) {
        if (nbEnfants > 3) {
            prixFinalTarifFamille = (nbAdultes-2)*TADULTE + (nbEnfants-3)*TENFANT + TFAMILLE;
        } else {
            prixFinalTarifFamille = (nbAdultes-2)*TADULTE + TFAMILLE;
        }
    } else {
        if (nbEnfants >= 3) {
            prixFinalTarifFamille = (nbEnfants-3)*TENFANT + TFAMILLE;
        } else {
            prixFinalTarifFamille = TFAMILLE;
        }
    }
    if (prixFinal > prixFinalTarifFamille) {
        return prixFinalTarifFamille;
    } else {
        return prixFinal;
    }
        }

//question 1
float prixEntree(int nbAdultes, int nbEnfants) {
    float prixFinal = 0;
    while (nbAdultes>=2 && nbEnfants>=3) {
        nbAdultes = nbAdultes - 2;
        nbEnfants = nbEnfants -3;
        prixFinal = prixFinal + TFAMILLE;
    }
    prixFinal = prixFinal + prixEntree2(nbAdultes,nbEnfants);
    return prixFinal;
}



int main() {
    printf("%.2f\n",prixEntree(2,1));
    printf("%.2f\n",prixEntree(2,2));
    printf("%.2f\n",prixEntree(2,3));
    printf("%.2f\n",prixEntree(6,3));
    printf("%.2f\n",prixEntree(1,3));
    printf("%.2f\n",prixEntree(5,7));
    printf("%.2f\n",prixEntree(6,8));
    printf("%.2f\n",prixEntree(10,0));
    printf("%.2f\n",prixEntree(0,4));
    return 0;
}