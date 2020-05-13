/*
    Given an array in which all numbers in rang 1..n appears only once, except for one number that appears twice.
    It is required to find that number.

    Using some simple math instead of naive solution:
        1-   sum(1..n) = n(n+1)/2
        2-   sum(arr)
        3-   required number = result in step 2 - result in step 1
*/

#include<stdio.h>

typedef unsigned char uint8;
typedef unsigned short uint16;

void whichIsTwice(uint8 *, uint8);


int main(){
    uint8 arr[] = {1,3,4,2,5,7,6,8,5}; // answer = 5
    uint8 L = sizeof(arr)/sizeof(arr[0]);  // the length of the array

    whichIsTwice(arr, L);
}

void whichIsTwice(uint8 * arr, uint8 L){

    /*
        since L = the length and the range is 1..n
        so, n = L-1
        n(1+n)/2 = (L-1)(1+L-1)/2 = (L-1)*L/2
    */
    uint16 sumN = ((L-1) * L) / 2;

    uint16 sumArr = 0;
    for(int i=0; i<L; i++){
        sumArr += arr[i];
    }

    printf("The duplicate number is %d", sumArr-sumN);
}