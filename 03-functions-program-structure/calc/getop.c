#include <stdio.h>
#include <ctype.h>

#include "getop.h"
#include "getch.h"

int getop(char num[])
{
    int i, c;

    while ((c = getch()) == ' ' || c == '\t');
    num[0] = c;

    if (!isdigit(c) && c != '.') {
        num[1] = '\0';
        return c;
    }

    i = 0;
    if (isdigit(c)) {
        while (isdigit((num[++i] = c = getch())));
    }

    if (c == '.') {
        while (isdigit((num[++i] = c = getch())));
    }
    num[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }
    return NUM_OP;
}