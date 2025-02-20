#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTAB 1
#define MAX 300
#define MIN -200

// Question 1
void init_temp(float *tab, int min, int max, int lentab)
{
    for (int i = 0; i < lentab; i++)
    {
        float val = (((double)rand() / (double)2147483648 * (max - min) + min) / 10.0);
        tab[i] = val;
    }
}

// question 2
float moy_temp(float *tab, int lentab)
{
    int moyenneFinale = 0;
    for (int i = 0; i < lentab; i++)
    {
        moyenneFinale = moyenneFinale + tab[i];
    }
    return (moyenneFinale*1.0 / lentab*1.0);
}

//Question 2, problème, la fraction donne une valeur entière

// question 3

float moyenne_temp_negatif(float *tab, int lentab)
{
    int nbJoursNegatifs = 0;
    float temp = 0;
    for (int i = 0; i < lentab; i++)
    {
        if (tab[i] < 0)
        {
            temp = temp + tab[i];
            nbJoursNegatifs++;
        }
    }

    if (!nbJoursNegatifs) {
        printf("Aucune temperature au-dessous de zero\n");
        return -1;
    }
    return (((float)temp)/nbJoursNegatifs);
}

int main()
{
    //srand(time(NULL));
    float tab[MAXTAB];
    init_temp(tab, MIN, MAX, MAXTAB);
    for (int j = 0; j < MAXTAB; j++)
    {
        printf("tab[%d] = %f\n", j, tab[j]);
    }
    printf("Moyenne = %f\n", moy_temp(tab, MAXTAB));
    printf("Moyenne Jours glacés = %f\n", moyenne_temp_negatif(tab, MAXTAB));
    return 0;
}
