/*Centigrade to fahrenheit*/
#include<stdio.h>
void main(){
    float c,f;
    printf("Enter temperature in centigrade: ");
    scanf("%f",&c);
    f=(c*9/5)+32;
    printf("\n%f",f);
}