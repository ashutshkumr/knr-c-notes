#include <stdio.h>

#define FAHR_LOWER 0
#define FAHR_UPPER 300

int main()
{
    int lower, upper, step;
    float fahr, cel;

    lower = FAHR_LOWER;
    upper = FAHR_UPPER;
    step = 20;

    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper) {
        cel = (fahr - 32) * 5.0 / 9.0;
        printf("%10.0f\t%7.1f\n", fahr, cel);
        
        fahr += step;
    }

    printf("\nFahrenheit\tCelsius\n");
    for (fahr = 300; fahr >= 0; fahr -= step) {
        printf("%10.0f\t%7.1f\n", fahr, (fahr - 32) * 5.0 / 9.0);
    }

    return 0;
}