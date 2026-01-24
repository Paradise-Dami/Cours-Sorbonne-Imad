#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"

cellule_t *creerListe(int n)
{
  /* cree une liste de n entiers saisi par l'utilisateur
    renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete = NULL;
  cellule_t *ptr;

  printf("Saisie des %d elements de la liste\n", n);
  for (i = 0; i < n; i++)
  {
    printf("Element %d :", i + 1);
    scanf("%d", &val);
    ptr = malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}

void AfficherListeInt(cellule_t *liste)
{
  if (liste->suivant == NULL)
  {
    printf("%d\n", liste->donnee);
  }
  else
  {
    AfficherListeInt(liste->suivant);
    printf("%d\n", liste->donnee);
  }
}

int nb_occurences(int val, cellule_t *liste)
{
  if (liste == NULL)
  {
    return 0;
  }
  if (liste->suivant == NULL)
  {
    if (liste->donnee == val)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if (liste->donnee == val)
    {
      return nb_occurences(val, liste->suivant) + 1;
    }
    else
    {
      return nb_occurences(val, liste->suivant);
    }
  }
}

int tous_plus_grand(int val, cellule_t *liste)
{
  if (liste == NULL)
  {
    return 0;
  }
  if (liste->suivant == NULL)
  {
    return liste->donnee >= val;
  }
  else
  {
    return (liste->donnee >= val) && tous_plus_grand(val, liste->suivant);
  }
}

cellule_t *maximum(cellule_t *liste)
{
  if (liste == NULL)
  {
    return NULL;
  }

  cellule_t *maxCellule = liste;
  cellule_t *courant = liste->suivant;

  while (courant != NULL)
  {
    if (courant->donnee > maxCellule->donnee)
    {
      maxCellule = courant;
    }
    courant = courant->suivant;
  }

  return maxCellule;
}

int renvoyer_val_element_pos(int pos, cellule_t *liste)
{
  if (liste == NULL)
  {
    return 0;
  }
  cellule_t *courant = liste;
  int i = 0;

  while (courant->suivant != NULL && i < pos)
  {
    courant = courant->suivant;
    i++;
  }
  return courant->donnee;
}

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2)
{
  if (liste1 == NULL)
  {
    return liste2;
  }
  if (liste2 == NULL)
  {
    return liste1;
  }
  cellule_t *courant = liste1;
  while (courant->suivant != NULL)
  {
    courant = courant->suivant;
  }
  courant->suivant = liste2;
  return liste1;
}

int nb_maximum(cellule_t *liste)
{
  if (liste == NULL)
  {
    return 0;
  }
  int max_val = liste->donnee;
  int compteur = 0;
  cellule_t *courant = liste;
  while (courant != NULL)
  {
    if (courant->donnee > max_val)
    {
      max_val = courant->donnee;
      compteur = 1;
    }
    else if (courant->donnee == max_val)
    {
      compteur++;
    }
    courant = courant->suivant;
  }
  return compteur;
}
