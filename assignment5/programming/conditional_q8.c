#include <stdio.h>

int conditional(int x, int y, int z){
    int mask = ~!!x + 1;
    return (y & mask) | (z & ~mask);
}

int main(){
    printf("conditional(2,4,5)    = %d\n", conditional(2,4,5));
    printf("conditional(0,4,5)    = %d\n", conditional(0,4,5));
    printf("conditional(-1,7,10)  = %d\n", conditional(-1,7,10));
    printf("conditional(0,7,10)   = %d\n", conditional(0,7,10));
    return 0;
}