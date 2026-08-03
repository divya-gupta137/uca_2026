#include <stdio.h>

int bang(int x)
{
    return (((x | (~x + 1)) >> 31)+1);
}

int main()
{
    printf("bang(0)   = %d\n", bang(0));
    printf("bang(3)   = %d\n", bang(3));
    printf("bang(-3)  = %d\n", bang(-3));
    printf("bang(100) = %d\n", bang(100));
    printf("bang(-1)  = %d\n", bang(-1));

    return 0;
}