#include <stdio.h>

void escape(const char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i)
    {
        switch (from[i]) {
        case '\n':
            to[i] = '\\';
            to[++i] = 'n';
            break;
        case '\t':
            to[i] = '\\';
            to[++i] = 't';
            break;
        default:
            to[i] = from[i];
        }
    }
    to[i] = '\0';
}

int main()
{
    char from[] = "hello there \tthis sequence\ncontains escapable chars";
    char to[sizeof(from)+100];
    
    escape(from, to);
    printf("escaped string: %s\n", to);
    return 0;
}