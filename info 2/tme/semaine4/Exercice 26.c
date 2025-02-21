#include <stdio.h>

// question 1
void fusion(int *tab1, int *tab2, int taille1, int taille2, int *tab3)
{
    int i = 0, j = 0;
    while ((i < taille1) && (j < taille2))
    {
        if ((tab1[i] <= tab2[j]) && (i < taille1))
        {
            tab3[i] = tab1[i];
            printf("%da\n",tab3[i + j]);
            i++;
        }
        else if (j < taille2)
        {
            
            tab3[i + j] = tab2[j];
            printf("%db\n",tab3[i + j]);
            j++;
        }
    }
}

int main()
{
    int tab1[2] = {0, 2}, tab2[1] = {0}, taille1 = 2, taille2 = 1;
    int tab3[taille1 + taille2];
    fusion(tab1, tab2, taille1, taille2, tab3);
    for (int k = 0; k < taille1 + taille2; k++)
    {
        printf("tab[%d] = %d\n", k, tab3[k]);
    }

    return 0;
}