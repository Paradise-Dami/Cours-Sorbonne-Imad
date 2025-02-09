#include <stdio.h>

// question 1
void echange(int *v1, int *v2)
{
    int a = *v2;
    *v2 = *v1;
    *v1 = a;
}

// question 2
void tri(int *a, int *b)
{
    if (!((*a)<(*b))) {
        echange(a,b);
    }
}

void tri_3(int *a, int *b, int *c) {
    tri(a,b);
    tri(b,c);
    tri(a,b);
}

int main()
{
    int d = 2;
    int e = 99;
    int f = 0;
    printf("v1 = %d, v2 = %d, v3 = %d\n", d, e, f);
    tri_3(&d, &e, &f);
    printf("v1 = %d, v2 = %d, v3 = %d\n", d, e, f);
    return 0;
}