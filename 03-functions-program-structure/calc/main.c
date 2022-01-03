#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "getop.h"

int main()
{
    int optype, op2;
    char num[MAX_OP];
    
    printf("enter postfix operators / operands:\n");
    while ((optype = getop(num)) != EOF) {
        switch (optype) {
            case NUM_OP:
                push(atof(num));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '\n':
                dump_stack();
                break;
            default:
                printf("unknown input: %s\n", num);
                break;
        }
    }

    return 0;
}