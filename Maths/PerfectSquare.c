/*
    Given an array of numbers, 
    return an all the numbers from the array that qualify as perfect squares. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef unsigned char uint8;
typedef unsigned short uint16;

void isPerfectSquare(uint16*, uint8, uint16*, uint8*);

int main(){
    uint16 arr1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
    uint16 arr2[] = {45,46,47,48,49,49,49,50,64,64,64,64,70,75,76,81,81,90,95,96,100};

    uint8 len1 = sizeof(arr1)/sizeof(arr1[0]);
    uint8 len2 = sizeof(arr2)/sizeof(arr2[0]);

    uint16* res1 = (uint16*)malloc(len1*sizeof(uint16));
    uint16* res2 = (uint16*)malloc(len2*sizeof(uint16));

    uint8 lenR1, lenR2;

    isPerfectSquare(arr1, len1, res1, &lenR1);
    isPerfectSquare(arr2, len2, res2, &lenR2);

    for(uint8 i=0; i<lenR1; i++)
        printf("%d ", res1[i]);
    
    printf("\n");
    
    for(uint8 i=0; i<lenR2; i++)
        printf("%d ", res2[i]);

    free(res1);
    free(res2);
}

void isPerfectSquare(uint16* arr, uint8 lenArr, uint16* result, uint8* lenR){
    uint8 r = 0;
    *lenR = 0;
    for(uint8 i=0; i<lenArr; i++){
        uint16 half = arr[i]/2;
        for(uint16 h=1; h<half; h++){
            if(h*h == arr[i]){
                result[r] = arr[i];
                r++;
                (*lenR)++;
                break;
            }
        }
    }
}