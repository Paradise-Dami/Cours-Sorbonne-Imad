#include <stdio.h>
#define MAX 5

int premier(int n) {
    int i;
    if (n<2) {
        return 0;
    }
    for (i = 2; i<=n; i++){
        if ((n%i == 0)) {
            return 1;
        }
    }
    return 0;
}

int main() {
   printf("%d\n", premier(4));
    return 0;
}