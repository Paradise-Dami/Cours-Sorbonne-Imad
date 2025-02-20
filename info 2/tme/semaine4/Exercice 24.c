#include <stdio.h>


//question 1
int indiceInsert(int *tab, int taille, int nbElements, int el)
{
    int indice = 0;
    if (nbElements < taille)
    {
        while ((indice < nbElements) && (tab[indice] > el))
        {
            indice++;
        }
        if (tab[indice] == el)
        {
            return -1;
        }
        return indice;
    }
    return -1;
}

//question 2



int main()
{
    return 0;
}