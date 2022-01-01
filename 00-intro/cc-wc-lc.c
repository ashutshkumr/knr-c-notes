#include <stdio.h>
#define IN 1 /* inside word */
#define OUT 0 /* outside word */

/* prints char, word and line count, and prints each word on a separate line */
int main()
{
    int c, wc, lc, cc, state;

    for (wc = cc = lc = 0, state = OUT; (c = getchar()) != EOF;) {
        ++cc;
        if (c == '\n') {
            ++lc;
            state = OUT;
        }
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
        } else if (state == OUT) {
            putchar('\n');
            state = IN;
            ++wc;
        }

        putchar(c);
    }

    printf("cc: %d, wc: %d, lc: %d, EOF: %d\n", cc, wc, lc, EOF);

    return 0;
}