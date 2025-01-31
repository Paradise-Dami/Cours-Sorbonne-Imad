#include <stdio.h>
#include <math.h>
#include <assert.h>
//Question 1

int discriminant(int a, int b, int c) {
    return (b*b)-(4*a*c);
}

//Question 2

float afficheRacine(int a, int b, int c) {
    float x1;
    float x2;
    int delta;
    delta = discriminant(a,b,c);
    x1 = (-b-sqrt(delta))/(2*a);
    x2 = (-b+sqrt(delta))/(2*a);
    printf("x1 = %f, x2 = %f\n",x1,x2);
    return x1,x2;
}


int main(){
    //Question 3
    printf("%d\n",discriminant(4,4,1));
    afficheRacine(4,4,1);
    afficheRacine(4,6,1); 
    afficheRacine(-7,-5,-1);
    return 0;
}

