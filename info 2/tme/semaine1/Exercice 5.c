#include <stdio.h>
#include <math.h>
#include <assert.h>
//Question 1

int discriminant(int a, int b, int c) {
    return (b*b)-(4*a*c);
}

//Question 2

void afficheRacines(int a, int b, int c) {
    float x1;
    float x2;
    int delta;
    delta = discriminant(a,b,c);
    if (delta < 0) {
        printf("Pas de racine reelle\n");
    } else {
        x1 = (-b+sqrt(delta))/(2*a);
        x2 = (-b-sqrt(delta))/(2*a);
        if (delta == 0) {
            printf("La racine double est %.2f\n",x1);
        } else {
        printf("Les deux racines sont %.2f et %.2f\n",x1,x2);
    }
    }
}


int main(){
    //Question 3
    afficheRacines(2,5,3);
    afficheRacines(4,6,1); 
    afficheRacines(-7,-5,-1);
    return 0;
}

