#include<stdio.h>
#include<string.h>

int stringLength(char* string){
    int length = 0;
    int i=0;
    while(string[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

char* insertString(char* string, char ch, int pos){
    int len = stringLength(string);
    char str[len+1];
    for(int i=0; i<(len+1); i++){
        if()
    }
}

char* delete(char* string, int pos){
    for(int i=pos-1; string[i]!='\0'; i++){
        string[i-1] = string[i]; 
    }
} 

int main(){
    char a[20]= "Hello World";
    printf("%d",stringLength(a));
    return 0;
}