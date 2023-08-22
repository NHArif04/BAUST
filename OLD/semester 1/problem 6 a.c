#include<stdio.h>
void main(){
    int sum=0, arr[3][4]={{25,18,5,20},{3,16,9,19},{2,34,6,48}};
    float average;
    for(int i=0; i<3*4; i++) 
        sum += arr[i/4][i%4];
    average = sum/(3.00*4.00);
    printf("sum is : %d\naverage is :%f",sum,average);
}