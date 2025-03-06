#include <stdio.h>

//question 1

int lenchaine(char *chaine) {
    int i = 0;
    int len = 0;
    while (chaine[i] != '\0') {
        i++;
        if (chaine[i] != ' ') {
            len++;
        }
    }
    return len;
}

//question 2
int main()
{
    char chaine[4] = "aaa";
    printf("len(aaa) = %d", lenchaine(chaine));
    return 0;
}