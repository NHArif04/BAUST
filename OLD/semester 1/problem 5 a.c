#include<stdio.h>
struct employee{
    char name[20];
    char address[100];
    int age;
};

int main(){
    struct employee a[7];
    for(int i=0; i<5; i++){
        printf("\nEnter employee no. i+1 name:");
        getchar();
        scanf("%[^\n]s",a[i].name);
        printf("\nEnter employee no. i+1 adress:");
        getchar();
        scanf("%[^\n]s",a[i].address);
        printf("\nEnter employee no. i+1 age:");
        getchar();
        scanf("%d",&a[i].age);
    }
    for(int i=0;i<5;i++){
        printf("\nEnter employee no. i+1 name: %s",a[i].name);
        printf("\nEnter employee no. i+1 adress: %s",a[i].address);
        printf("\nEnter employee no. i+1 age: %d",a[i].age);
    }
}