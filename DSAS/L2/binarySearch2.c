#include<stdio.h>
#include<stdbool.h>
#define size(a) sizeof(a)/sizeof(a[0]);

void binarySearch(int arr[], int low, int high, int value){
    int mid = low + (high-low)/2;
    if(value == arr[mid])
        return true;
    arr[mid] < value ? (low = mid) : ( high = mid);
    binarySearch(arr, low, high, value);
    ("not found");
}

void main(){
    int array[] = {1,2,3,4,5,8,9,10,11,12,13};
    int length = size(array);
    printf("%s",binarySearch(array, 0, length-1,12)?"found":"not found");
}