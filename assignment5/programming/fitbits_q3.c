/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

#include <stdio.h>

int fitsBits(int x, int n) {
  int shift = 32-n;                  
  return !(((x << shift) >> shift) ^ x);
}


//we have 32 bit integer and we want to reperesent it in 3 bits so as of nowwe cant even compare the numbers as they are representing in differen tn umber of bits so what we will do is we will try to make this 3 bit integer into a 32 bit integer , if the value comes out to be same te