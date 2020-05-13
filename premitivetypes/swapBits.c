/*
    Given an integer and incices of 2 bits, swap the bits
*/

#include<stdio.h>

#define GETBIT(n,i) (n>>i)&1
#define TOGBIT(n,i) n^(1<<i)

typedef unsigned short uint16;
typedef unsigned char uint8;

void swapBits(uint16, uint8, uint8);


int main(){

    uint16 n = 25; // n = 11001

    swapBits(n, 0, 3 ); // bits 0,3 are one's ---> n=11001 ---> n=25 >>> the same
    swapBits(n, 1, 2 ); // bits 1,2 are zero's ---> n=11001 ---> n=25 >>> the same
    swapBits(n, 0, 2 ); // bits 0,2  ---> n=11101 ---> n=28
}


void swapBits(uint16 n, uint8 i, uint8 j){
    uint8 biti = GETBIT(n ,i);
    uint8 bitj = GETBIT(n, j);

    if(biti==bitj)
        printf("Bits %d and %d are the same.\n", i, j);
    else{
        n = TOGBIT(n, i);
        n = TOGBIT(n, j);

        printf("Then number after swap bits %d and %d is %d\n", i, j, n);
    }
}