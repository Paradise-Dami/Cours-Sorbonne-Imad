#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Question 2.1.1 partie 1

// Version 1
int *alloue_tableau(int n)
{
    int *T = (int *)malloc(n * sizeof(int));
    return T;
}
// Version 2
void alloue_tableau2(int **T, int n)
{
    *T = (int *)malloc(n * sizeof(int));
}

// Question 2.1.2 partie 1
void desalloue_tableau(int *T)
{
    free(T);
}

// Question 2.1.3 partie 1
void remplir_tableau(int *T, int V, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int valeur = rand() % V; /* après ça  */
        T[i] = valeur;
    }
}

// Question 2.1.4 partie 1
void afficher_tableau(int *T, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]");
}

// Question 2.2.1 partie 1
int algo1(int *T, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += (T[i] - T[j]) * (T[i] - T[j]);
        }
    }
    return sum;
}

// Question 2.2.2 partie 1
int algo2(int *T, int n)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += T[i] * T[i];
        sum2 += T[i];
    }
    return 2 * n * sum1 - 2 * sum2 * sum2;
}

// Question 2.3 partie 1

// Question 2.4.1 partie 2

int **alloue_matrice(int n)
{
    int *mat = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    return mat;
}

// Question 2.4.2 partie 2
void desalloue_matrice(int **matrice, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrice[i]);
    }
    free(matrice);
}

// Question 2.4.3 partie 2
void remplir_matrice(int **matrice, int V, int n)
{
    srand(time(NULL));
    for (int j = 0; j < n, j++)
    {
        for (int i = 0; i < n; i++)
        {
            int valeur = rand() % V;
            (matrice[j])[i] = valeur;
        }
    }
}

// Question 2.4.3 partie 2
void afficher_matrice(int **matrice, int n) {}

// Question 2.5.1 partie 1

int **multiplier_matrice(int **matrice1, int **matrice2, int n)
{
}

int main()
{
    return 0;
}
