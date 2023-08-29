#include<stdio.h>
#include<stdbool.h>
#define size(a) sizeof(a)/sizeof(a[0]);

bool binarySearch(int arr[], int high, int value){
    int mid = high/2, low= 0;
    while(low <= high){
        mid = low+(high-low)/2;
        if(arr[mid] < value){
            low = mid+1;
        }
        else if(arr[mid] > value){
            high = mid-1;
        }
        else{
            printf("\nFound at index: %d", mid);
            return mid;
        }
    }
    printf("\nNot Found");
    return false;
}

void main(){
    int array[] = {1,2,3,4,5,8,9,10,11,12,13};
    int length = size(array);
    int index = binarySearch(array, length-1, 12);
}