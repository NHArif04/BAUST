#include<stdio.h>
void mul(int *a, int *b){
    *a*=*b;
    printf("%d",*a);
}
int main(){
    int val1 = 300, val2 = 400;
    int *ptr1,  *ptr2;
    ptr1 = &val1;
    ptr2 = &val2;
    mul(ptr1,ptr2);
}