#include <stdio.h>

#include "stack.h"

static double stack[STACK_SIZE];
static int top = -1;

void push(double num)
{
    if (top < STACK_SIZE - 1) {
        stack[++top] = num;
    } else {
        printf("error: stack full !\n");
    }
}

double pop(void)
{
    if (stack_empty()) {
        printf("error: stack empty !\n");
        return 0;
    }

    return stack[top--];
}

int stack_empty(void)
{
    return top == -1;
}

void dump_stack(void)
{
    int i;

    printf("stack: ");
    for (i = 0; i <= top; ++i) {
        printf("%lf ", stack[i]);
    }
    printf("\n");
}