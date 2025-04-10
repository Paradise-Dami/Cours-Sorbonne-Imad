#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun �l�ment n'a la valeur val */
element_t *Recherche_val(element_t *ensemble, int val)
{
  if (ensemble == NULL)
  {
    return NULL;
  }
  if (ensemble->valeur == val)
  {
    return ensemble;
  }
  else
  {
    return Recherche_val(ensemble->suivant, val);
  }
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t *Ajout_tete_ensemble(element_t *ensemble, int val, int freq)
{
  if (ensemble == NULL)
  {
    element_t *ensemble = malloc(sizeof(element_t));
    ensemble->valeur = val;
    ensemble->frequence = freq;
    ensemble->suivant = NULL;
    return ensemble;
  }
  element_t *isTherePtr = Recherche_val(ensemble, val);

  if (isTherePtr != NULL)
  {
    isTherePtr->frequence = isTherePtr->frequence + freq;
    return isTherePtr;
  }
  element_t *ancienneTete = malloc(sizeof(element_t));
  ancienneTete->valeur = ensemble->valeur;
  ancienneTete->frequence = ensemble->frequence;
  ancienneTete->suivant = ensemble->suivant;
  ensemble->valeur = val;
  ensemble->frequence = freq;
  ensemble->suivant = ancienneTete;
  return ensemble;
}

element_t *Supprime_total_element_ensemble(element_t *ensemble, int val)
{
  if (ensemble == NULL)
  {
    return NULL;
  }
  if (Recherche_val(ensemble, val) == NULL)
  {
    return ensemble;
  }
  element_t *elToKill = Recherche_val(ensemble, val);
  element_t *actuel = ensemble;
  while (actuel->suivant != elToKill)
  {
    actuel = actuel->suivant;
  }
  actuel->suivant = elToKill->suivant;
  free(elToKill);
  return ensemble;
}

element_t *Supprime_element_ensemble(element_t *ensemble, int val)
{
  if (ensemble == NULL)
  {
    return NULL;
  }
  element_t *elToModify = Recherche_val(ensemble, val);
  if (elToModify == NULL)
  {
    return ensemble;
  }
  if (elToModify->frequence > 1)
  {
    elToModify->frequence = elToModify->frequence - 1;
    return ensemble;
  }else {
    return Supprime_total_element_ensemble(ensemble, val);
  }
}

/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble)
{
  element_t *ptr = ensemble;

  while (ptr != NULL)
  {
    printf("val : %d, frequence : %d\n", ptr->valeur, ptr->frequence);
    ptr = ptr->suivant;
  }
}

/* Saisie des n elements d'un ensemble */
element_t *Creation_ensemble(int n)
{
  element_t *ensemble = NULL;

  int i = 0;
  int val;

  for (i = 0; i < n; i++)
  {
    printf("Saisie d'un entier: ");
    scanf("%d", &val);
    ensemble = Ajout_tete_ensemble(ensemble, val, 1);
  }
  return ensemble;
}
