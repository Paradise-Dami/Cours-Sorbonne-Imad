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
element_t *ajout_tete_ensemble(element_t *ensemble, int val, int freq)
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
void affiche_ensemble(element_t *ensemble)
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
    ensemble = ajout_tete_ensemble(ensemble, val, 1);
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
  if (element == NULL)
  {
    return NULL;
  }

  element_t *is_there = Recherche_val(element, val);
  if (is_there != NULL)
  {
    if (is_there->frequence == 1)
    {
      element = Supprime_total_element_ensemble(element, val);
    }
    else
    {
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
      while (actuel->suivant != NULL && actuel->suivant->valeur < val)
      {
        actuel = actuel->suivant;
      }

      nouvelle_valeur->valeur = val;
      nouvelle_valeur->frequence = freq;
      nouvelle_valeur->suivant = actuel->suivant;
      actuel->suivant = nouvelle_valeur;
      return ensemble;
    }
  }
  else
  {
    is_there->frequence = is_there->frequence + freq;
    return ensemble;
  }
}

element_t *Supprime_element_ensemble_trie(element_t *liste, int val)
{
  if (liste == NULL)
    return NULL;

  // Cas particulier : la valeur est en tête
  if (liste->valeur == val)
  {
    if (liste->frequence > 1)
    {
      liste->frequence--;
      return liste;
    }
    else
    {
      element_t *tmp = liste->suivant;
      free(liste);
      return tmp;
    }
  }

  element_t *courant = liste;
  while (courant->suivant != NULL && courant->suivant->valeur <= val)
  {
    if (courant->suivant->valeur == val)
    {
      if (courant->suivant->frequence > 1)
      {
        courant->suivant->frequence--;
      }
      else
      {
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

element_t *Supprime_total_element_ensemble_trie(element_t *liste, int val)
{
  if (liste == NULL)
    return NULL;

  // Cas particulier : suppression en tête
  if (liste->valeur == val)
  {
    element_t *tmp = liste->suivant;
    free(liste);
    return tmp;
  }

  element_t *courant = liste;
  while (courant->suivant != NULL && courant->suivant->valeur <= val)
  {
    if (courant->suivant->valeur == val)
    {
      element_t *a_supprimer = courant->suivant;
      courant->suivant = a_supprimer->suivant;
      free(a_supprimer);
      return liste;
    }
    courant = courant->suivant;
  }

  return liste; // valeur non trouvée
}

int taille(element_t *ensemble)
{
  if (ensemble == NULL)
  {
    return 0;
  }
  return ensemble->frequence + taille(ensemble->suivant);
}

element_t *Supprime_frequence_inf_seuil(element_t *ensemble, int seuil)
{
  if (ensemble == NULL)
  {
    return NULL;
  }

  while (ensemble != NULL && ensemble->frequence < seuil)
  {
    element_t *temp = ensemble;
    ensemble = ensemble->suivant;
    free(temp);
  }

  element_t *actuel = ensemble;
  while (actuel->suivant != NULL)
  {
    if (actuel->suivant->frequence < seuil)
    {
      element_t *prochain = actuel->suivant;
      actuel->suivant = prochain->suivant;
      free(prochain);
    }
    else
    {
      actuel = actuel->suivant;
    }
  }
  return ensemble;
}

element_t *ajout_suivant(element_t *ensemble, int val, int freq)
{
  element_t *nouvel_el = malloc(sizeof(element_t));
  nouvel_el->valeur = val;
  nouvel_el->frequence = freq;

  if (ensemble == NULL)
  {
    nouvel_el->suivant = NULL;
    return nouvel_el;
  }

  nouvel_el->suivant = ensemble->suivant;
  ensemble->suivant = nouvel_el;
  return nouvel_el;
}

int inclus_rec(element_t *ens1, element_t *ens2)
{
  /* renvoie 1 si ens1 est inclus dans ens2, 0 sinon */
  if (ens1 == NULL)
  {
    return 1;
  }
  if (ens2 == NULL)
  {
    return 0;
  }
  if (ens1->valeur < ens2->valeur)
  {
    return 0;
  }
  else if (ens1->valeur == ens2->valeur)
  {
    if (ens1->frequence > ens2->frequence)
    {
      return 0;
    }
    return inclus_rec(ens1->suivant, ens2->suivant);
  }
  return inclus_rec(ens1, ens2->suivant);
}

element_t *unionME(element_t *ens1, element_t *ens2)
{
  element_t *nouvel_ens = NULL;

  while (ens1 != NULL && ens2 != NULL)
  {
    if (ens1->valeur < ens2->valeur)
    {
      nouvel_ens = ajout_tete_ensemble(nouvel_ens, ens1->valeur, ens1->frequence);
      ens1 = ens1->suivant;
    }
    else if (ens1->valeur > ens2->valeur)
    {
      nouvel_ens = ajout_tete_ensemble(nouvel_ens, ens2->valeur, ens2->frequence);
      ens2 = ens2->suivant;
    }
    else
    {
      nouvel_ens = ajout_tete_ensemble(nouvel_ens, ens1->valeur, ens1->frequence + ens2->frequence);
      ens1 = ens1->suivant;
      ens2 = ens2->suivant;
    }
  }

  while (ens1 != NULL)
  {
    nouvel_ens = ajout_tete_ensemble(nouvel_ens, ens1->valeur, ens1->frequence);
    ens1 = ens1->suivant;
  }

  while (ens2 != NULL)
  {
    nouvel_ens = ajout_tete_ensemble(nouvel_ens, ens2->valeur, ens2->frequence);
    ens2 = ens2->suivant;
  }
  return nouvel_ens;
}
