#include<stdio.h>
int main(){
    int x,y,z=2;
    z++; //3
    z++; // 4
    z++; //5
    y= z++; //5 = 6
    x= ++z; // 7 = 7
    y--; //4
    x++; //8
    printf("The value of x = %d, y= %d and z= %d",x,y,z);
}