#include<stdio.h>
#include<math.h>

int main(){
    int n = 100;
    for(int i=1; i<sqrt(n); i++ ){
        printf("%d",i);                 //O(/n)
    }
}