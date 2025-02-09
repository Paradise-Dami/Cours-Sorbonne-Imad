#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20

//question 1

int valeur_aleatoire(int min, int max)
{
  int val;
  do
  {
    val = (int)((double)rand() / (double)2147483648 * (max - min) + min);
  } while ((val <= min) || (val >= max));
  
  return val;
}

//question 2
void pos_neg_zero(int nbAl, int *ptr_negatif, int *ptr_zero, int *ptr_positif) {
    if (!nbAl) {
      (*ptr_zero)++;
    } else {
      if (nbAl<0) {
        (*ptr_negatif)++;
      } else {
        (*ptr_positif)++;
      }
    }
  }

int main()
{
  srand(time(NULL));
  int i = 0;
  int negatif = 0;
  int zero = 0;
  int positif = 0;
  int valeur = 0;
  while (++i <= NB_VALEURS) {
    valeur = valeur_aleatoire(VMIN,VMAX);
    pos_neg_zero(valeur, &negatif, &zero, &positif);
  }
  printf("nbNeg:%d\nnbZeros:%d\nnbPos:%d\n", negatif, zero, positif);
  return 0;
}