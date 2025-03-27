#include <stdio.h>
#define N 3

// question 1
int isElementcoderunner(int *tab, int taille, int elt)
{
    int indiceplusgrand = 0;
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] == elt)
        {
            indiceplusgrand = i;
        }
    }
    if (tab[indiceplusgrand] == elt)
    {
        return indiceplusgrand;
    }
    return -1;
}

int isElement(int *tab, int taille, int elt)
{
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] == elt)
        {
            return i;
        }
    }
    return -1;
}

int isElementrec(int *tab, int taille, int elt)
{
    if (taille == 0)
    {
        return -1;
    }
    if (tab[taille - 1] == elt)
    {
        return taille - 1;
    }
        return isElementrec(tab, taille - 1, elt);
}

int recherche_rec_aux(int *tab, int taille,int indice, int elem) {
    {
        if (taille == indice)
        {
            return -1;
        }
        if (tab[taille - 1] == elt)
        {
            int a = isElementrec(tab, taille - 1, elt);
            if ((taille-1) <= a){
                return taille-1;
            } else {
                return a;
            }
        }
            return isElementrec(tab, taille - 1, elt);
    }
}

int main()
{
    int tab[N] = {3, 2, 1};
    //printf("%d", isElementrec(tab, N, 3));
    return 0;
}