#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("sizeof short: %ld\n", sizeof(short int));
    printf("sizeof int: %ld\n", sizeof(int));
    printf("sizeof long: %ld\n", sizeof(long int));
    printf("sizeof char: %ld\n", sizeof(char));
    printf("sizeof float: %ld\n", sizeof(float));
    printf("sizeof double: %ld\n", sizeof(double));
    printf("sizeof long double: %ld\n", sizeof(long double));

    printf("max short: %d\n", SHRT_MAX);
    printf("max unsigned int: %u\n", UINT_MAX);
    printf("max double: %lf\n", DBL_MAX);
    printf("max long double: %Lf\n", LDBL_MAX);
}