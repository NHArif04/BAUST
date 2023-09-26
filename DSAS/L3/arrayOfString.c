#include<stdio.h>
#define size(a) sizeof(a)/sizeof(a[0])


int main(){
    char* name = "Nahid";
    char* fullName[] = {"Nahid","Hasan","Arif"};
    for(int i = 0; i<size(name); i++){
        printf("%c ",name[i]);
    }

    for(int i = 0; i<size(fullName); i++){
        printf("\n%s ",fullName[i]);
    }
}