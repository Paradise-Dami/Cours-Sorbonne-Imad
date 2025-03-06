#include <stdio.h>

// question 1
int indiceInsert(int tab[], int el, int nbElements, int taille)
{
    int indice = 0;
    if (nbElements < taille)
    {
        while ((indice < nbElements) && (tab[indice] < el))
        {
            indice++;
        }
        if (indice < nbElements && tab[indice] == el)
        {
            return -1;
        }
        return indice;
    }
    return -1;
}

// question 2

int insertElt(int tab[], int el, int *nbElements, int taille)
{
    int indEl = indiceInsert(tab, el, *nbElements, taille);
    if (indEl == -1)
    {
        return 0;
    }
    for (int i = *nbElements; i > indEl; i--)
    {
        tab[i] = tab[i - 1];
    }
    tab[indEl] = el;
    *nbElements = *nbElements + 1;

    return 1;
}

int main()
{
    int tab[5] = {2, 4, 6},
        taille = 20,
        nbElements = 3,
        el = 10;
    printf("%d\n", indiceInsert(tab, 7, 3, 5));
    printf("%d\n", indiceInsert(tab, 4, 3, 5));
    insertElt(tab, el, &nbElements, taille);
    for (int k = 0; k < nbElements; k++)
    {
        printf("tab[%d] = %d\n", k, tab[k]);
    }
    return 0;
}