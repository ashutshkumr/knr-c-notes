#include <stdio.h>

#define MAXLEN 10

void itoa(int num, char ascii[])
{
    int i, j;
    char rev_ascii[MAXLEN];

    j = 0;
    if (num < 0) {
        ascii[j++] = '-';
        num = -num;
    }

    i = -1;
    do {
        rev_ascii[++i] = '0' + (num % 10);
    } while((num /= 10) > 0);

    for (; i >= 0; ++j, --i) {
        ascii[j] = rev_ascii[i];
    }
    ascii[j] = '\0';
}

int main()
{
    char ascii[MAXLEN];
    int num = 223;

    itoa(num, ascii);
    printf("num: %d, ascii: %s\n", num, ascii);
    return 0;
}