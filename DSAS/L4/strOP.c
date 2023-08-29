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
    for(int i=len; i>=pos-1; i--){
        string[i+1] = string[i];
    }
    string[pos-1] = ch;
    string[stringLength(string)] = '\0'; 
    return string;
}

char* deleteString(char* string, int pos){
    int i=pos; 
    while(string[i]!='\0'){
        string[i-1] = string[i]; 
        i++;
    }
    string[i-1] = '\0';
    return string;
}

char* stringConcat(char* str1, char* str2){
    int len1 = stringLength(str1), len2 = stringLength(str2);
    int size = len1+len2;
    char string[size];
    for(int i=0; i<size; i++){
        if(i<len1){
            string[i]=str1[i];
        }
        else{
            string[i] = str2[i-len1];
        }
    }
    return string;
}

int main(){
    char a[20];
    puts("Enter a string: ");
    fgets(a, sizeof(a), stdin);
    a[stringLength(a)-1] = '\0';
    printf("Original String: %s\n",a);
    printf("Length: %d\n",stringLength(a));

    char ch;
    puts("Enter a new character to insert: ");
    int pos;
    scanf("%c",&ch);
    puts("Enter position to insert: ");
    scanf("%d",&pos);
    insertString(a,ch,pos);
    printf("After Insertion: %s\n",a);

    int positionDelete;
    puts("Enter Position to Delete: ");
    scanf("%d",&positionDelete);
    deleteString(a,positionDelete);
    printf("After Deletion: %s\n",a);
    
    puts("Enter a new string to concat: ");
    char str[20];
    scanf("%[^\n]s",str);
    //fgets(str, sizeof(str), stdin);
    str[stringLength(str)-1] = '\0';
    char *newStr = stringConcat("a","str");
    printf("Concat string: %s",newStr);
    return 0;
}
