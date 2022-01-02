#include <stdio.h>

#define MAXLEN 100

int get_line(char line[])
{
    int c, cc;

    for (cc = 0; (c = getchar()) != EOF && cc < MAXLEN - 1; ++cc) {
        line[cc] = c;
        if (c == '\n') {
            ++cc;
            break;
        }
    }

    line[cc] = '\0';
    return cc;
}

void reverse(char line[], char reversed_line[])
{
    int i, j, len;
    
    len = -1;
    while (line[++len] != '\n');

    for (i = 0, j = len - 1; i < len; ++i, --j) {
        reversed_line[i] = line[j];
    }
    
    reversed_line[i] = '\0';
}

int main()
{
    char line[MAXLEN];
    char reversed_line[MAXLEN];
    
    while (get_line(line) != 0) {
        reverse(line, reversed_line);
        printf("reversed: %s\n", reversed_line);
    }

    return 0;
}