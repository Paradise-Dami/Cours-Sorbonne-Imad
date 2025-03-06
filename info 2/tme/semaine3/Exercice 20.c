#include <stdio.h>

// question 1
int nb_racines(int a, int b, int c)
{
    int delta;
    delta = (b * b) - (4 * a * c);
    if (delta < 0)
    {
        return 0;
    }
    else
    {
        if (delta == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}

// question 2
void nb_racines_delta(int *delta, int a, int b, int c)
{
    *delta = (b * b) - (4 * a * c);
    return nb_racines(a, b, c);
}

// question 3

int racines(int a, int b, int c, float *x1, float *x2)
{
    int delta = (b * b) - (4 * a * c);
    float y1;
    float y2;
    if (delta < 0)
    {
        return 0
    }
    else
    {
        y1 = (-b + sqrt(delta)) / (2 * a);
        y2 = (-b + sqrt(delta)) / (2 * a);
        *x1 = y1;
        *x2 = y2;
        if (delta > 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}

int main()
{
    int delta;
    int x1;
    int x2;
    /* code */
    return 0;
}
