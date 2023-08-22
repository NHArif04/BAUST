/** 
**   Linear Searching Algorithm
*/

#include<stdio.h>
#define size(a) sizeof(a)/sizeof(a[0]);

int linearSearch(int array[], int length, int value){
    for(int i=0; i<length; i++){
        if(value == array[i]){
            printf("\n%d is found in array at index : %d\n",value, i);
            return i;
        }

    }
    printf("\n%d is not found\n", value);
}

int main(){
    int arr[] = {2,5,9,10,20,90,100};
    int len = size(arr);
    linearSearch(arr, len, 100);
    linearSearch(arr, len, 105);
}