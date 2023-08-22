#include<stdio.h>
#define size(a) sizeof(a)/sizeof(a[0])

int main(){
    int arr[] = {50,10,20};
    int *ptr = &arr[size(arr)-1];
    int i=3;
    while(i--){
        printf("Address : %x      Value : %d\n",ptr--, *ptr);
    }
}
