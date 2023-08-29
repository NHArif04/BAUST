#include<stdio.h>

int stringLength(char* string){
    int length = 0;
    int i=0;
    while(string[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

//brute force algorithm
int patternMarchingAlgo1(char* string, char* pattern){
    int lenS = stringLength(string), lenP = stringLength(pattern);
    for (int i = 0; i<(lenS-lenP+1); i++){ 
        for(int j=0; j<lenP; j++){
            if(string[i+j] != pattern[j]){
                break;
            }
            if(j == (lenP-1)){
                return i; 
            }
        }
    }
    return -1;
}


int main(){
    char str[] = "abcdefabcgh";
    char pat[] = "def";
    int pos = patternMarchingAlgo1(str, pat);
    printf("%d\n",pos );
    return 0;
}