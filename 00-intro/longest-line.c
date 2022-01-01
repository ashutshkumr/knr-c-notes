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

void copy_line(char to[], char from[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i);
}

int main()
{
    int i, len, longest_len;
    char line[MAXLEN], longest_line[MAXLEN];

    for (len = longest_len = 0; (len = get_line(line)) != 0; ) {
        if (len > longest_len) {
            copy_line(longest_line, line);
            longest_len = len;
        }
    }

    printf("longest line (%d): %s", longest_len, longest_line);

    return 0;
}