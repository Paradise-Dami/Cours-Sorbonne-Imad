#include <stdio.h>
#include <stdlib.h>

//Question 2.1.1 partie 1


//Version 1
int *alloue_tableau(int n){
    int *T = (int *)malloc(n*sizeof(int));
    return T;
}
//Version 2
void alloue_tableau2(int **T, int n){
    *T = (int *)malloc(n*sizeof(int));
}

//Question 2.1.2 partie 1
void desalloue_tableau(int *T){
    free(T);
}

//Question 2.1.3 partie 1
void remplir_tableau(int *T, int V, int n){
    srand(time(NULL));
    for (int i = 0, i < n, i++){
        int valeur = rand() % V; /* après ça  */
        T[i] = valeur;
    }
}

//Question 2.1.4 partie 1
void afficher_tableau(int *T, int n){
    printf("[")
    for (int i = 0, i < n, i++){
        printf("%d ", T[i]);
    }
    printf("]");
}


//Question 2.2.1 partie 1
int algo1(int *T){
    for (int i = 0)
}



int main(){
    return 0;
}
