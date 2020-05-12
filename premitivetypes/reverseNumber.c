#include<stdio.h>

typedef signed short sint32;

void reverse(sint32);


int main(){

    printf("%d, rev= ", 8);
    reverse(8); // one-digit positive number

    printf("%d, rev= ", -5);
    reverse(-5); // one-digit negative number

    printf("%d, rev= ", 10);
    reverse(10); // two-digit positive number, zero units
    
    printf("%d, rev= ", 17);
    reverse(17); // two-digit positive number

    printf("%d, rev= ", -20);
    reverse(-20); // two-digit negative number, zero uints
    
    printf("%d, rev= ", -49);
    reverse(-49); // two-digit negative number
    
    printf("%d, rev= ", 0147);
    reverse(0147); // multi-digit positive number
    
    printf("%d, rev= ", -5147);
    reverse(-5147); // multi-digit negative number
    
    printf("%d, rev= ", 0);
    reverse(0); // zero
}


void reverse(sint32 n){
    char neg = 0;

    if(n<0){
        n = -1 * n;
        neg = 1;
    }

    sint32 nrev = 0;
    
    while(n>0){
        nrev = n%10 + nrev*10;
        n = n/10;
    }

    if(neg == 1)
        nrev = -1 * nrev;   

    printf("%d\n", nrev);
}