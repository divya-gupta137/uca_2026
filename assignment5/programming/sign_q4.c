/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */

#include <stdio.h>

int sign(int x){
    return (x >> 31) | (!!x);
}

int main(){
    printf("sign(130)  = %d\n", sign(130));
    printf("sign(-23)  = %d\n", sign(-23));
    printf("sign(0)    = %d\n", sign(0));
    printf("sign(1)    = %d\n", sign(1));
    printf("sign(-1)   = %d\n", sign(-1));
    return 0;
}