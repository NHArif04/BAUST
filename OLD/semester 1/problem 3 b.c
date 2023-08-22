/*Even number that are divisible by 6 or 9 range 1-100*/
#include<stdio.h>
void main(){
    for(int i=1; i<=100;i++){
        if(i%6==0 || i%9==0 )
            printf("%d ",i);
    }
}