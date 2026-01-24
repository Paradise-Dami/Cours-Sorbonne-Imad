#include <stdio.h>
#include "multi_ensembles.h"

int main() {
  element_t *ens1 = NULL;
  element_t *ens2 = NULL;

  // ens1 = [ (1,2), (3,1), (5,2) ] (ordre croissant)
  ens1 = ajout_tete_ensemble(ens1, 5, 2);
  ens1 = ajout_tete_ensemble(ens1, 3, 1);
  ens1 = ajout_tete_ensemble(ens1, 1, 2);

  // ens2 = [ (2,3), (3,2), (4,1) ] (ordre croissant)
  ens2 = ajout_tete_ensemble(ens2, 4, 1);
  ens2 = ajout_tete_ensemble(ens2, 3, 2);
  ens2 = ajout_tete_ensemble(ens2, 2, 3);

  printf("Ensemble 1 : ");
  affiche_ensemble(ens1);
  printf("Ensemble 2 : ");
  affiche_ensemble(ens2);

  element_t *res = unionME(ens1, ens2);

  printf("Union (ordre décroissant) : ");
  affiche_ensemble(res);
}