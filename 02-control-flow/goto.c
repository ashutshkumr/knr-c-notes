#include <stdio.h>

int main()
{
    int i, j, k;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            for (k = 0; k < 10; ++k) {
                if (i == j && j == k && k == 5) {
                    goto out;
                }
            }
        }
    }

    out:
    printf("i: %d, j: %d, k: %d\n", i, j, k);

    return 0;
}