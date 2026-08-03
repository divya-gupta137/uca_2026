#include <stdio.h>

int isPower2(int x){
    return !!x & !(x >> 31) & !(x & (x + ~0));
}

int main(){
    printf("isPower2(0)  = %d\n", isPower2(0));
    printf("isPower2(1)  = %d\n", isPower2(1));
    printf("isPower2(2)  = %d\n", isPower2(2));
    printf("isPower2(4)  = %d\n", isPower2(4));
    printf("isPower2(5)  = %d\n", isPower2(5));
    printf("isPower2(8)  = %d\n", isPower2(8));
    printf("isPower2(16) = %d\n", isPower2(16));
    printf("isPower2(-8) = %d\n", isPower2(-8));
    return 0;
}

// we must check 3 conditions 
//1. should != 0
//2. should be positiv
//3. each bit should be 0 

