#include <stdio.h>

#include "getch.h"

static int getchbuf[GETCHBUF_SIZE];
static int top = -1;

int getch(void)
{
    return top == -1 ? getchar() : getchbuf[top--];
}

void ungetch(int c)
{
    if (top < GETCHBUF_SIZE - 1) {
        getchbuf[++top] = c;
    } else {
        printf("error: getchbuf full !");
    }
}