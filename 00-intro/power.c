#include <stdio.h>

long power(int, int);

int main()
{
    printf("power(2, 8) = %ld\n", power(2, 8));
    return 0;
}

long power(int base, int exponent)
{
    int val;
    for (val = 1; exponent > 0; --exponent) {
        val *= base;
    }

    return val;
}
