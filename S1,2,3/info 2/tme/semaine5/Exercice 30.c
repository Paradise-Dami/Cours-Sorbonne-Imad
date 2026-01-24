#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 2
#define MAX 5

// question 1
int generertabbool(int *tab, int max, int min)
{
    // on suppose que tab est de longeur max+1
    int taille = (rand() % (max - min + 1)) + min;
    //printf("%d", taille);
    for (int i = 0; i < taille; i++)
    {
        tab[i] = rand() % 2;
        //printf("%d", tab[i]);
    }
    tab[taille] = -1;
    return taille;
}

void affichertab(int *tab)
{
    printf("[");
    int i = 0;
    while (tab[i]!=-1) {
        printf("%d, ", tab[i]);
        i++;
    }
    printf("]\n");
}

// question 2
void compress_tab(int *tab_brut, int *tab_compress)
{
    int compteur = 0;
    int indice_tab_brut = 0;
    int indice_tab_compresse = 0;
    int valprec = tab_brut[0];
    while (tab_brut[indice_tab_brut] != -1)
    {
        if (valprec == tab_brut[indice_tab_brut])
        {
            compteur++;
        }
        else
        {
            tab_compress[indice_tab_compresse] = compteur;
            tab_compress[indice_tab_compresse + 1] = valprec;
            valprec = tab_brut[indice_tab_brut];
            compteur = 0;
            indice_tab_compresse++;
        }
        indice_tab_brut++;
    }
}

void decompress_tab(int *tab_brut, int *tab_compress)
{
    //2 chemin de la louette, lyon
    int compteur = 0;
    while (tab_compress[compteur] != -1) {
        for (int i = 0; i < tab_compress[compteur]; i++) {
        }
    }
}

int main()
{
    //srand(time(NULL));
    int tabnb[MAX + 1];
    int taille = generertabbool(tabnb, MAX, MIN);
    affichertab(tabnb);
    int tabnbcompress[2*(MAX + 1)];
    compress_tab(tabnb,tabnbcompress);
    affichertab(tabnbcompress);
    return 0;
}