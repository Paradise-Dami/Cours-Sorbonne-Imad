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
  if ((a > 0) && (b > 0) && (c > 0) && (d > 0))
  {
    *moyenne = ((float)(a + b + c + d)) / 4;
    if (a < b)
    {
      min_max(c, &a, &b);
      min_max(d, &a, &b);
    }
    else
    {
      min_max(c, &b, &a);
      min_max(d, &b, &a);
    }
    *min = a;
    *max = d;
  }
  else if ((a > 0) && (b > 0) && (c > 0) && (d <= 0))
  {
    *moyenne = ((float)(a + b + c)) / 3;
    if (a < b)
    {
      min_max(c, &a, &b);
      *min = c;
      *max = a;
    }
    else
    {
      min_max(c, &b, &a);
      *min = a;
      *max = c;
    }
    
  }
  else if ((a > 0) && (b > 0) && (c <= 0))
  {
    *moyenne = ((float)(a + b)) / 2;
    if (a < b)
    {
      *min = a;
      *max = b;
    }
    else
    {
      *min = b;
      *max = a;
    }
  }
  else if ((a > 0) && (b <= 0))
  {
    *min = a;
    *max = a;
    *moyenne = a;
  }
  else
  {
    *min = -1;
    *max = -1;
    *moyenne = -1;
  }
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