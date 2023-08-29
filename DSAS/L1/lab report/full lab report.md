```C
#include<stdio.h>
#define size(a) sizeof(a)/sizeof(a[0]);

void arrayTraverse(int* arr, int len){ //problem -> when trying to determine size of an array from another function
    printf("\nTraversing Array : ");
    for(int i = 0; i<len; i++){
        printf("%d ", *(arr+i)); //dereferencing the pointer to access each element => array[i]
    }
    printf("\n");
}

int arraySearch(int* arr, int len, int target){
    for(int i = 0; i<len; i++){
        if(target == *(arr+i)){
            printf("\n%d is found in index : %d\n", target, i);
            return i;
        }
    }
    printf("\n%d is not found\n", target);
    return 0;
}

void arrayInsert(int* arr, int len, int targetIndex, int value){
    int temp;
    for(int i = 0; i<len; i++){
        if(targetIndex<=i){
            temp = arr[i];
            arr[i] = value;
            value = temp;
        }
    }
    printf("\n%d inserted to the array at index : %d\n", value, targetIndex);
}

void arrayDelete(int* arr, int len, int target){
    int i= arraySearch(arr, len, target);
    printf("\n%d deleted to the array from index : %d\n", target, i);
    while(i<len){
            arr[i++] = arr[i+1];
    }
}

void main(){
    int array[] = {7, 13, 15, 27};
    int arr[15] = {50, 52, 53, 56, 57, 65, 75, 77, 79, 88};
    int length = size(array);
    int len = size(arr);
    arrayTraverse(array, length);
    int target = 13;
    int index = arraySearch(array, length, target);
    int val = 51;
    arrayInsert(arr, len, index, val);
    arrayTraverse(arr, len);
    arrayDelete(arr, len, val);
    arrayTraverse(arr, len);
}
```