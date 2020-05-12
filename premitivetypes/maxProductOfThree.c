#include<stdio.h>
#include<math.h>

typedef signed long sint16;
typedef signed long long sint64;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX3(x, y, z) (((MAX(x,y)) > (z)) ? (MAX(x,y)) : (z))
#define MIN3(x, y, z) (((MIN(x,y)) < (z)) ? (MIN(x,y)) : (z))

void maxProductOfThree(sint16*, char);


int main(){
    // all positive
    sint16 arr0[] = {1,5,7,3,15,11,7,10,2,2}; // res = 15*11*10 = 1650
    maxProductOfThree(arr0, 10);

    // all negative
    sint16 arr1[] = {-15,-5,-7,-12,-13,-4,-71}; // res = -5*-7*-4 = -140
    maxProductOfThree(arr1, 7);

    // positive and negative
    sint16 arr2[] = {-14,4,72,-9,15,-13,25,-40}; // res = 72*-14*-40 = 40320
    maxProductOfThree(arr2, 8);
}

void maxProductOfThree(sint16* arr, char length){
    sint64 maxNum = arr[0];
    sint64 minNum = arr[0];

    sint64 maxProd_2 = arr[0] * arr[1];
    sint64 minProd_2 = arr[0] * arr[1];

    sint64 maxProd_3 = arr[0] * arr[1] * arr[2];

    char i = 2; // counter to go through the array, it starts from 2 as we already visted the first two elements
    while(i<length){
        maxProd_3 = MAX3(maxProd_2*arr[i], minProd_2*arr[i], maxProd_3);
        maxProd_2 = MAX3(maxNum*arr[i], minNum*arr[i], maxProd_2);
        minProd_2 = MIN3(maxNum*arr[i], minNum*arr[i], minProd_2);
        maxNum = MAX(arr[i],maxNum);
        minNum = MIN(arr[i],minNum);

        i++;
    }
    
    printf("maxProdofThree = %d\n", maxProd_3);

}

