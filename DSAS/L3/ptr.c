#include<stdio.h>

int main(){
    int a[] = {3,65,5,6};
    int *p ;
    printf("%x\n",p); // 7
    p = a;
    printf("%d %d\n",*p, *p++); // 7
    printf("%d \n", ++*p);
    return 0;
}