#include <stdio.h>
#define VAL1 2
#define VAL2 7
#define VAL3 5
#define VAL4 9

// question 1
void min_max(int val, int *min, int *max)
{
  if ((*min) > (val))
  {
    *min = val;
  }
  else if ((*max) < (val))
  {

    *max = val;
  }
}

// question 2
void stats(int a, int b, int c, int d, int *min, int *max, float *moyenne)
{
  *moyenne = ((float)(a + b + c + d)) / 4;
  if (a < b)
  {
    min_max(b, &a, &d);
    min_max(c, &a, &d);
  } else {
    min_max(b, &d, &a);
    min_max(c, &d, &a);
  }
  *min = a;
  *max = d;
  // dabc
}

void afficher_resultat(float moyenne, int min, int max)
{
  printf("max = %d, min = %d, moy = %.2f\n", max, min, moyenne);
}

int main()
{
  float moy;
  int min, max;

  // vous devrez bien sur modifier les parametres d'appel de la fonction stats une fois cette derniere completee
  stats(VAL1, VAL2, VAL3, VAL4, &min, &max, &moy);

  // vous devrez bien sur modifier les parametres d'appel de la fonction afficher_resultat
  afficher_resultat(moy, min, max);

  return 0;
}