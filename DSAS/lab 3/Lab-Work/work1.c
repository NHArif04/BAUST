#include<stdio.h>


void linearSearchPointer(int* arr,int target){
    while(arr){
        if(*arr++ == target){
            printf("Found!");
            return;
        }
    }
    printf("not Found!");
}



int main(){
    int ara[] = {2,3,4,5};
    int key;
    printf("Value-to-Search:");
    scanf("%d",&key);
    int *ptr = ara;
    linearSearchPointer(ptr, key);
    return 0;
}