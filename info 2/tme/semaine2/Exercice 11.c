#include <stdio.h>

int jours(int nbconta, int popTotale, float doitEtreInfecte) {
    int infecte = 1;
    int jour = 0;
    while (((infecte*100.0)/popTotale) <= (doitEtreInfecte*1.0)) {
        //printf("%d,%d,%f\n",jour,infecte,((infecte*100.0)/popTotale));
        jour++;
        infecte = infecte*nbconta;
        printf("%f\n",((infecte*100.0)/popTotale));
    }
    return jour;
}

int main() {
    printf("jours:%d\n",jours(5,10000,50.0));
    return 0;

}