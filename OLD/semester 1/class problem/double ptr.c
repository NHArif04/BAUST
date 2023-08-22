#include<stdio.h>
int main(){
    int var=400;
    int *ptr, **ptr2;
    ptr=&var;
    ptr2=&ptr;
    printf("var = %d\n*ptr = %d\n**ptr2 = %d\nptr => %p\nptr2 => %p",var,*ptr,**ptr2,ptr,ptr2);
return 0;
}