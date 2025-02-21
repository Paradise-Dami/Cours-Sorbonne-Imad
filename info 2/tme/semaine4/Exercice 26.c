#include <stdio.h>
#include <stdlib.h>

// question 1
/*void fusion(int *tab1, int *tab2, int taille1, int taille2, int *tab3)
{
    int i = 0, j = 0;
    while ((i + j) < (taille1 + taille2))
    {
        if (i < taille1 + 1)
        {

            if (tab1[i] <= tab2[j])
            {
                printf("aaa\n");
                tab3[i + j] = tab1[i];
                i++;
            } else if (j < taille2 + 1)
            {

                if (tab1[i] > tab2[j])
                {
                    tab3[i + j] = tab2[j];
                    j++;
                }



            }
        }

        printf("%d,%d\n", i, j);
    }
    printf("%d", i + j);
}*/

int* fusion(int tab1[], int tab2[], int taille1, int taille2) {
    /* Réalise la fusion triée des tableaux triés tab1 et tab2 */
    int* resultat = (int*)malloc((taille1 + taille2) * sizeof(int));
    if (resultat == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    
    int i1 = 0, i2 = 0, i = 0;
    
    while (i1 < taille1 && i2 < taille2) {
        if (tab1[i1] < tab2[i2]) {
            resultat[i++] = tab1[i1++];
        } else {
            resultat[i++] = tab2[i2++];
        }
    }
    
    while (i1 < taille1) {
        resultat[i++] = tab1[i1++];
    }
    
    while (i2 < taille2) {
        resultat[i++] = tab2[i2++];
    }
    
    return resultat;
}


int main()
{
    int tab1[2] = {4, 5}, tab2[2] = {0, 7}, taille1 = 2, taille2 = 2;
    int *tab3;
    tab3 = fusion(tab1, tab2, taille1, taille2);
    for (int k = 0; k < taille1 + taille2; k++)
    {
        printf("tab[%d] = %d\n", k, tab3[k]);
    }

    return 0;
}