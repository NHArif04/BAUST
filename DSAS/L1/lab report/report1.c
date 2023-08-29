#include<stdio.h>
#define size(a) sizeof(a)/sizeof(a[0]);

void arrayTraversing(int* arr, int len){ //problem -> when trying to determine size of an array from another function
    printf("\nTraversing Array : ");
    for(int i = 0; i<len; i++){
        printf("%d ", arr[i]); //dereferencing the pointer to access each element => array[i]
    }
    printf("\n");
}

int arraySearching(int* arr, int len, int target){
    for(int i = 0; i<len; i++){
        if(target == *(arr+i)){
            printf("\n%d is found in index : %d\n", target, i);
            return i;
        }
    }
    printf("\n%d is not found\n", target);
    return 0;
}

void arrayInsertion(int* arr, int len, int targetIndex, int value){
    int temp;
    printf("\n%d inserted to the array at index : %d\n", value, targetIndex);
    for(int i = 0; i<len; i++){
        if(targetIndex<=i){
            temp = arr[i];
            arr[i] = value;
            value = temp;
        }
    }
}

void arrayDeletion(int* arr, int len, int target){
    int i= arraySearching(arr, len, target);
    printf("\n%d deleted to the array from index : %d\n", target, i);
    while(i<len){
            arr[i++] = arr[i+1];
    }
}

void main(){
    int array[] = {7, 13, 15, 27, 338};
    int arr[15] = {47, 50, 52, 53, 56, 57, 65, 75, 77, 79, 88, 338};
    int length = size(array);
    int len = size(arr);
    arrayTraversing(array, length);
    int target = 13, val = 51;
    int index = arraySearching(array, length, target);
    arrayInsertion(arr, len, index, val);
    arrayTraversing(arr, len);
    arrayDeletion(arr, len, val);
    arrayTraversing(arr, len);
}