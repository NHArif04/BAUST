#include<stdio.h>

int main2();

int main(){
    int a[10];
    int *ptr, **pptr;
    ptr = a;
    pptr = &ptr;
    printf("Address of pointer: %x\n",a);
    printf("Address of pointer: %x\n",ptr);
    printf("Address of pointer: %x\n",pptr);
    main2();
return 0;
}


int main2(){
    int var = 20;
    int* p = &var;
    int **pp = &p;
    printf("Address fo the var : %x\n",&var);
    printf("Address fo the var : %x\n",p);
    printf("Address fo the var : %x\n",*pp);
    *p = 25;
    printf("Address fo the var : %d\n",**pp);
    return 0;
}