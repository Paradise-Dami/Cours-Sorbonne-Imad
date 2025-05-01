#include <stdio.h>
#include "multi_ensembles.h"

int main() {
  printf("\n=== Test Suppression triée ===\n");
  element_t *liste = NULL;

  liste = Ajout_ensemble_trie(liste, 5, 2);
  liste = Ajout_ensemble_trie(liste, 8, 1);
  liste = Ajout_ensemble_trie(liste, 10, 3);
  liste = Ajout_ensemble_trie(liste, 12, 1);

  printf("Initial :\n");
  Affiche_ensemble(liste); // [5|2] -> [8|1] -> [10|3] -> [12|1]

  // Test suppression simple
  liste = Supprime_element_ensemble_trie(liste, 10); // 10 passe à 2
  Affiche_ensemble(liste); // [5|2] -> [8|1] -> [10|2] -> [12|1]

  // Suppression qui supprime un élément (fréquence 1)
  liste = Supprime_element_ensemble_trie(liste, 8);  // 8 disparaît
  Affiche_ensemble(liste); // [5|2] -> [10|2] -> [12|1]

  // Suppression totale d’un élément
  liste = Supprime_total_element_ensemble_trie(liste, 10);
  Affiche_ensemble(liste); // [5|2] -> [12|1]

  // Tentative de suppression d’un élément non présent
  liste = Supprime_element_ensemble_trie(liste, 99);
  Affiche_ensemble(liste); // [5|2] -> [12|1]
}