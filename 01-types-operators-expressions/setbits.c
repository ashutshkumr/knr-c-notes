#include <stdio.h>
#include <limits.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    return (x & ~(~(UINT_MAX << n) << p)) | ~(UINT_MAX << (p + n)) & (y << p);
}

int main()
{
    unsigned x = 0xAAFA, y = 0xAABB;
    printf("x: %x, y: %x, x: %x\n", x, y, setbits(x, 8, 4, y));
    return 0;
}
