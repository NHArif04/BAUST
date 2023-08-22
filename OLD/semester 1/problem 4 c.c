#include<stdio.h>
void main(){
    int org=5678, rev=0;
    while(org){
        rev = (rev*10 + org%10);
        org/=10;
    }
    printf("\n%d",rev);
}