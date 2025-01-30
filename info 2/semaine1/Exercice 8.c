#include <stdio.h>
#include <assert.h>
#define tarifAdulte 22.7
#define traifEnfant 10.75
#define tarifFamille 57.80

float prixEntree(int nbAdultes, int nbEnfants) {
    float prixFinal;
    prixFinal = 0;
    if ((nbAdultes <= 2) && (nbEnfants <= 3)) {
            prixFinal = prixFinal + nbAdultes*tarifAdulte + nbEnfants*traifEnfant;
        if (prixFinal > tarifFamille) {
            return tarifFamille;
        } else {
            return prixFinal;
        }
        } else {
            return tarifAdulte*(nbAdultes-2) + traifEnfant*(nbEnfants-3) + tarifFamille;
        }
            return prixFinal;
    }




int main() {
    printf("prixEntree(%d,%d) = %f\n", 2, 3, prixEntree(2,3));
    printf("prixEntree(%d,%d) = %f\n", 2, 2, prixEntree(2,2));
    printf("prixEntree(%d,%d) = %f\n", 2, 1, prixEntree(2,1));
    printf("prixEntree(%d,%d) = %f\n", 1, 3, prixEntree(1,3));
    return 0;
}