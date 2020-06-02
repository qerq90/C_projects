#include <stdio.h>

int bit_count_long(long a)
{
    int counter = 0;
    if(a < 0) {
        a *= -1;
        counter++;
    }

    while(a)
    {
        a >>= 1;
        if(a % 2) counter++;
    }

    return counter;
}

int bit_count_double(double a)
{
    int counter = 0;
    if(a < 0) {
        a *= -1;
        counter++;
    }

    long * pl = (long *)&a; // поскольку long и double имеют один и тот же размер,можно представить одно через другое
    long b = *pl;

    while(b)
    {
        b >>= 1;
        if(b % 2) counter++;
    }

    return counter;
}

int main(void)
{
    long a = -22;

    printf("%d\n", bit_count_long(a));

    double b = -1.3;

    printf("%d\n", bit_count_double(b));
 
    return 0;
}