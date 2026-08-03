/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
#include <stdio.h>

int getByte(int x, int n) {
  return ( x >> (n << 3) & 0xFF) ;
}

int main()
{
    int x = 0x12345678;
    printf("Byte 0 (LSB) = 0x%X\n", getByte(x, 0));
    printf("Byte 1       = 0x%X\n", getByte(x, 1));
    printf("Byte 2       = 0x%X\n", getByte(x, 2));
    printf("Byte 3 (MSB) = 0x%X\n", getByte(x, 3));
    return 0;
}