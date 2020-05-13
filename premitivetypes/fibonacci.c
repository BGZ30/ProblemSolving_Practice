/*
    fibo = 0, 1, 1, 2, 3, 5, 8, 13, ....
    
    to find the nth fibo number:
    instead of using the recursive approach, it's better to use an iterative approach
        - O(n) time and O(1) space.
*/

#include<stdio.h>

typedef unsigned short uint16;
typedef unsigned long uint32;

void fibonacci(uint16);

int main(){
    fibonacci(0);
    fibonacci(1);
    fibonacci(2);
    fibonacci(15);
}

void fibonacci(uint16 n){
    uint16 current = 1;
    uint16 previous = 0;
    uint32 fibo = 0;

    for(char i=1; i<=n; i++){
        fibo = current + previous;
        previous = current;
        current = fibo;
    }

    printf("fibo %d = %d\n", n,fibo);
}