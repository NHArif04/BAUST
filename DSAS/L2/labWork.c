#include<stdio.h>
#include<stdbool.h>
#define size(a) sizeof(a)/sizeof(a[0]);

bool binarySearchReverse(int arr[], int high, int value){
    int mid = high/2, low= 0;
    while(low <= high){
        mid = low+(high-low)/2;
        if(arr[mid] > value){
            low = mid+1;
        }
        else if(arr[mid] < value){
            high = mid-1;
        }
        else{
            printf("\nFound at index: %d", mid);
            return true;
        }
    }
    printf("\nNot Found");
    return false;
}

bool binarySearchShort(int arr[], int high, int value){
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
            return true;
        }
    }
    printf("\nNot Found");
    return false;
}

void binarySearch(int arr[], int high, int value){
    arr[high] >= arr[0] ? binarySearchShort(arr, high, value) : binarySearchReverse(arr, high, value);
}

void main(){
    int array[] = {100, 80, 70, 50, 20, 2};
    int arr[] = {1,2,3,4,5,7,11,12,14,15};
    int len = size(arr);
    int length = size(array);
    binarySearch(array, length-1, 100);
    binarySearch(arr, len-1, 11);
}