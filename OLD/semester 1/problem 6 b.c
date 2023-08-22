#include<stdio.h>
void main(){
    int a[5] = {3,2,1,45,5};
    int max=a[0],index= 0;
    for(int i=1; i<5;i++){
        if(a[i]>max){
            max = a[i];
            index = i;
        }
    }
    printf("max : %d\nindex : %d",max,index);
}