#include <stdio.h>
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */

 
int logicalShift(int x, int n){
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main(){
    int x = 0x87654321;
    int n = 4;
    printf("Original Number : 0x%X\n", x);
    printf("Shift Amount    : %d\n", n);
    printf("\nLogical Shift Result = 0x%X\n", logicalShift(x, n));
    return 0;
}