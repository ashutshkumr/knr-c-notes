#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define MAXLINES 10

int str_cmp(const char *s1, const char *s2)
{
    for (; *s1 == *s2 && *s1 && *s2; ++s1, ++s2);
    return *s1 - *s2;
}

int num_cmp(const char *s1, const char *s2)
{
    double d1, d2;

    d1 = atof(s1);
    d2 = atof(s2);

    if (d1 < d2) {
        return -1;
    } else if (d1 > d2) {
        return 1;
    } else {
        return 0;
    }
}

void strsort(char **lines, int (*cmp)(const void *, const void *))
{
    int i, j;
    char *tmp;

    for (i = 0; *lines[i]; ++i) {
        for (j = i; *lines[j]; ++j) {
            if ((*cmp)(lines[i], lines[j]) > 0) {
                tmp = lines[i];
                lines[i] = lines[j];
                lines[j] = tmp;
            }
        }
    }
}

void get_lines(char **lines)
{
    int i, j, c;

    printf("enter lines: \n");
    for (i = 0; i < MAXLINES - 1; ++i) {
        for (j = 0; (c = getchar()) != '\n'; ++j) {
            if (c == EOF) {
                break;
            }
            lines[i][j] = c;
        }
        lines[i][j] = '\0';
        if (c == EOF) {
            break;
        }
    }
    
    lines[++i][0] = '\0';
}

int main(int argc, char **argv)
{
    int i, read_num = 0;
    char lines[MAXLINES][MAXLEN];

    /* create **char */
    char *linesptr[MAXLINES];
    for (i = 0; i < MAXLINES; ++i) {
        linesptr[i] = lines[i];
    }
    
    while (*argv) {
        if (str_cmp(*argv, "-n") == 0) {
            read_num = 1;
            break;
        }
        ++argv;
    }

    get_lines(linesptr);
    strsort(linesptr, (int (*)(const void *, const void *)) (read_num ? num_cmp : str_cmp));

    printf("sorted lines:\n");
    for (i = 0; *linesptr[i]; ++i) {
        printf("%s\n", linesptr[i]);
    }

    return 0;
}