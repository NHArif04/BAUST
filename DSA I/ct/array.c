#include<stdio.h>

void insert(int arr[], int size, int index, int value){
    for(int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}

void delete(int arr[], int size, int index){
    for(int i = index; i<size; i++){
        arr[i] = arr[i+1];
    }
}

void traverse(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,2,4,3,5,6}, index=3, value=56;
    int size = sizeof(arr)/sizeof(arr[0]);
    traverse(arr, size);
    size++;
    insert(arr, size, index, value);
    traverse(arr, size);
    delete(arr, size, index);
    size--;
    traverse(arr, size);
    return 0;
}