#include <stdio.h>
#include <assert.h>
#define TADULTE 22.7
#define TENFANT 10.75
#define TFAMILLE 57.80

float prixEntree(int nbAdultes, int nbEnfants) {
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

int main() {
    printf("prixEntree(%d,%d) = %0.2f\n", 2, 3, prixEntree(2,3));
    printf("prixEntree(%d,%d) = %0.2f\n", 6, 3, prixEntree(6,3));
    printf("prixEntree(%d,%d) = %0.2f\n", 2, 1, prixEntree(1,3));
    printf("prixEntree(%d,%d) = %0.2f\n", 5, 7, prixEntree(5,7));
    printf("prixEntree(%d,%d) = %0.2f\n", 10, 0, prixEntree(10,0));
    printf("prixEntree(%d,%d) = %0.2f\n", 0, 4, prixEntree(0,4));
    return 0;
}