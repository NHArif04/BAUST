#include<stdio.h>

int main(){
    int arr[] = {50,10,20};
    int *ptr = arr;
    int i=3;
    while(i--){
        printf("Address : %x      Value : %d\n",ptr++, *ptr);
    }
}