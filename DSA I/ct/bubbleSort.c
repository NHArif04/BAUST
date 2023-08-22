#include<stdio.h>

void bubbleSort(int arr[], int n){
    int i, j;
    for(i=0; i<n-1;i++){
        for(j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                arr[j]^=arr[j+1]^=arr[j]^=arr[j+1];   //single line swap=> x^=y^=x^=y;
            }
        }
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[]={1,5,4,2,3,6,5};
    bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}