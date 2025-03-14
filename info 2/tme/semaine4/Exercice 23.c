#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTAB 31
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
    float moyenneFinale = 0;
    for (int i = 0; i < lentab; i++)
    {
        moyenneFinale = moyenneFinale + tab[i];
    }
    float moyenne = moyenneFinale/lentab; 
    return moyenne;
}

// question 3

float moy_temp_gel(float *tab, int lentab)
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
    float moyenne = temp/nbJoursNegatifs; 
    return moyenne;
}

//same

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
