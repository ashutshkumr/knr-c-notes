#include <stdio.h>

#define MAXLEN 100

int get_line(char line[])
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; line[i++] = c);
    
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}

int strindex(char str[], const char pat[])
{
    int i, j, k;

    for (i = 0; str[i] != '\0'; ++i) {
        for (j = i, k = 0; pat[k] != '\0' && pat[k] == str[i]; ++k, ++i);
        if (pat[k] == '\0') {
            return j;
        }
    }

    return -1;
}

int main()
{
    char line[MAXLEN];
    char pat[] = "second";

    while (get_line(line)) {
        if (strindex(line, pat) > -1) {
            printf("%s", line);
        }
    }
    
    return 0;
}