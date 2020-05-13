/*
    Given an integer, find the closest integer with the same weight.
    Here weight is defined as the count of set bits in the binary representation of the integer.

    Ex:
        - 2 => 0b10  --> 0b01 => 1
        - 5 => 0b101 --> 0b110 => 6
        - 8 => 0b1000 --> 0b100 => 4
        - 7 => 0b111 --> 0b1011 => 11
        - 3 =>0b11 --> 0b101 => 5
    
    Method:
        swap the first different two adjacent bits
*/

#include<stdio.h>

#define GETBIT(n, i) (n>>i)&1
#define TOGBIT(n, i) n^(1<<i)

typedef unsigned short uint16;

void closestInteger(uint16);

int main(){

    closestInteger(1);  // answe = 2
    closestInteger(7);  // answe = 11
    closestInteger(2);  // answe = 1
    closestInteger(8);  // answe = 4
    closestInteger(5);  // answe = 6
    closestInteger(4);  // answe = 2
    closestInteger(0);  // answe = 0 --> all zeros
    closestInteger(65535);  // answe = 65535  --> this is 0b111111111111111 (2^16)-1  --> all ones
}


void closestInteger(uint16 n){

    // find a different adjacent bits, and swap them
    for(char i=0; i<15; i++){
        if((GETBIT(n, i) ^ GETBIT(n, i+1)) == 1){

            printf("the number is %d, ", n);

            n = TOGBIT(n, i);
            n = TOGBIT(n, i+1);

            printf("the closest number is %d\n", n);
            // a pair was found, so it's the closest number, so stop search
            return;
        }
    }

    printf("the number is %d, and all bits are the same.\n", n);

}