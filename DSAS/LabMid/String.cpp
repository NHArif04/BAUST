#include<iostream>
#include<cstring>

int stringLength(const char* str){
    int length = 0;
    int i=0;
    while(str[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

const char* insertString(const char* str, char ch, int pos){
    int len = stringLength(str);
    cons
}