#include<stdio.h>

int main(){
    long a,b;
    scanf("%ld%ld",&a,&b);
    printf("%s\n",(a+b%2==0)?"Black":"White");
    return 0;
}