#include <stdlib.h>
#include <stdio.h>

int *f(int *x, int y) {
   int *z = malloc(sizeof(int));
   int w = *x;
   *x = 5;
   y = 2;
   *z = *x * y - w;
   return z;
}

int main() {
   int a = 2;
   int b = 5;
   int *c;
   c=f(&a, b);
   printf("%d %d %d\n",a,b,*c);
   free(c);
   return 0;
}