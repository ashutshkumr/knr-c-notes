#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100

int hchartoi(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    
    return -1;
}

long htoi(const char str[])
{
    long val;
    int i, cval, pos;
    for (i = val = pos = 0; str[i] != '\0'; ++i, ++pos) {
        if (i == 1 && str[0] == '0' && (str[i] == 'x' || str[i] == 'x')) {
            val = 0;
            pos = 0;
        } else {
            cval = hchartoi(str[i]);
            if (cval == -1) {
                return -1;
            }

            val = (val * 16) + cval;
        }
    }

    return val;
}

int main()
{
    char c, str[MAXLEN];
    int i;
    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (isspace(c)) {
            break;
        }
        str[i] = c;
    }
    str[i] = '\0';

    printf("%s: %ld\n", str, htoi(str));
    return 0;
}