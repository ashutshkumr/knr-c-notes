#include <stdio.h>

int binsearch(int items[], int len, int item)
{
    int low, high, mid;

    for (low = 0, high = len - 1; low <= high; ) {
        mid = (high + low) / 2;

        if (items[mid] < item) {
            low = mid + 1;
        } else if (items[mid] > item) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main()
{
    int items[] = {1, 3, 5, 7, 8, 10, 21, 34, 52};
    int len = sizeof(items) / sizeof(int);

    printf("index: %d\n", binsearch(items, len, 7));
    return 0;
}