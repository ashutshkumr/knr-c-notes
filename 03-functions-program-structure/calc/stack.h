#ifndef _STACK_H_
#define _STACK_H_

#define STACK_SIZE 100

int stack_empty(void);
double pop(void);
void push(double);
void dump_stack(void);

#endif