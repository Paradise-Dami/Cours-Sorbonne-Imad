#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun �l�ment n'a la valeur val */
element_t *Recherche_val(element_t *ensemble, int val)
{
  while (ensemble != NULL)
  {
    if (ensemble->valeur == val)
    {
      return ensemble;
    }
    ensemble = ensemble->suivant;
  }
  return NULL;
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t *Ajout_tete_ensemble(element_t *ensemble, int val, int freq)
{
  if (ensemble == NULL)
  {
    ensemble = malloc(sizeof(element_t));
    ensemble->valeur = val;
    ensemble->frequence = freq;
    return ensemble;
  }
  element_t *nouvelle_tete;
  nouvelle_tete = malloc(sizeof(element_t));
  element_t *is_there = Recherche_val(ensemble, val);
  if (is_there == NULL)
  {
    nouvelle_tete->valeur = val;
    nouvelle_tete->frequence = freq;
    nouvelle_tete->suivant = ensemble;
    return nouvelle_tete;
  }
  else
  {
    is_there->frequence = is_there->frequence + freq;
    return ensemble;
  }

  return NULL;
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

element_t *Supprime_total_element_ensemble(element_t *element, int val)
{
  if (element == NULL)
  {
    return NULL;
  }

  if (element->valeur == val)
  {
    element_t *temp = element->suivant;
    free(element);
    return temp;
  }
  element_t *el_actu = element;
  while (el_actu->suivant != NULL)
  {
    if (el_actu->suivant->valeur == val)
    {
      element_t *val_del = el_actu->suivant;
      el_actu->suivant = val_del->suivant;
      free(val_del);
      break;
    }
    el_actu = el_actu->suivant;
  }
  return element;
}

element_t *Supprime_element_ensemble(element_t *element, int val)
{
    if (element == NULL) {
        return NULL;
    }

    element_t *is_there = Recherche_val(element, val);
    if (is_there != NULL) {
        if (is_there->frequence == 1) {
            element = Supprime_total_element_ensemble(element, val);
        } else {
            is_there->frequence--;
        }
    }

    return element;
}

element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq)
{
  if (ensemble == NULL)
  {
    ensemble = malloc(sizeof(element_t));
    ensemble->valeur = val;
    ensemble->frequence = freq;
    return ensemble;
  }
  element_t *is_there = Recherche_val(ensemble, val);
  if (is_there == NULL)
  {
    element_t *nouvelle_valeur = malloc(sizeof(element_t));
    if (val < ensemble->valeur)
    {
      nouvelle_valeur->valeur = val;
      nouvelle_valeur->frequence = freq;
      nouvelle_valeur->suivant = ensemble;
      return nouvelle_valeur;
    }
    else
    {
      element_t *actuel = ensemble;
      while (actuel->suivant != NULL && actuel->suivant->valeur < val) {
        actuel = actuel->suivant;
    }
    
      nouvelle_valeur->valeur = val;
      nouvelle_valeur->frequence = freq;
      nouvelle_valeur->suivant = actuel->suivant;
      actuel->suivant = nouvelle_valeur;
      return ensemble;
    }
  }
  else {
    is_there->frequence = is_there->frequence + freq;
    return ensemble;
  }
}

element_t *Supprime_element_ensemble_trie(element_t *liste, int val) {
  if (liste == NULL) return NULL;

  // Cas particulier : la valeur est en tête
  if (liste->valeur == val) {
      if (liste->frequence > 1) {
          liste->frequence--;
          return liste;
      } else {
          element_t *tmp = liste->suivant;
          free(liste);
          return tmp;
      }
  }

  element_t *courant = liste;
  while (courant->suivant != NULL && courant->suivant->valeur <= val) {
      if (courant->suivant->valeur == val) {
          if (courant->suivant->frequence > 1) {
              courant->suivant->frequence--;
          } else {
              element_t *a_supprimer = courant->suivant;
              courant->suivant = a_supprimer->suivant;
              free(a_supprimer);
          }
          return liste;
      }
      courant = courant->suivant;
  }

  return liste; // valeur non trouvée
}

element_t *Supprime_total_element_ensemble_trie(element_t *liste, int val) {
  if (liste == NULL) return NULL;

  // Cas particulier : suppression en tête
  if (liste->valeur == val) {
      element_t *tmp = liste->suivant;
      free(liste);
      return tmp;
  }

  element_t *courant = liste;
  while (courant->suivant != NULL && courant->suivant->valeur <= val) {
      if (courant->suivant->valeur == val) {
          element_t *a_supprimer = courant->suivant;
          courant->suivant = a_supprimer->suivant;
          free(a_supprimer);
          return liste;
      }
      courant = courant->suivant;
  }

  return liste; // valeur non trouvée
}
