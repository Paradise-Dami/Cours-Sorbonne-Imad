#include <stdio.h>


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
    int prixFinal = 0;
    while (nbAdultes>=2 && nbEnfants>=3) {
        nbAdultes = nbAdultes - 2
        nbEnfants = nbEnfants -3
        prixFinal = prixFinal + 57.80
    }
    prixFinal = prixFinal + prixEntree2(nbAdultes,nbEnfants)
    return prixFinal;
}



int main() {

    return 0;
}