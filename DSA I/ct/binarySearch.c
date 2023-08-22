#include<stdio.h>

void binarySearch(int arr[], int len, int target){
    int low = 0;
    int high = len-1;
    int mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(target==arr[mid]){
            printf("Element found at index %d\n",mid);
            return;
        }else if(target>arr[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    printf("Not found\n");
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    binarySearch(arr, sizeof(arr)/sizeof(arr[0]), 10);
    return 0;
}