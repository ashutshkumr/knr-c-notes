#ifndef _GETCH_H_
#define _GETCH_H_

#define GETCHBUF_SIZE 100

int getch(void);
void ungetch(int c);

#endif