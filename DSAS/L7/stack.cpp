#include<iostream>
#include<cstdbool>

using namespace std;

#define MAX 4

int top=-1;
int stack[MAX];



bool isEmpty(){
    return (top==-1)? true: false;
}


bool isFull(){
    return MAX==(top-1)? true : false;
}

int peak(){
    if(isEmpty()){cout<<"Stack is empty"<<endl; 
    return -1;
    }else {
        return stack[top];
    }
}

void push(int value){
    if(isFull()){
        cout<<"Overflow"<<endl;
    }else{
        top++;
        stack[top]=value;
    }
}

int pop(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }else{
        return stack[top--]; 
    }
}

void traverse(){
    for(int i=top; i>=0; i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main(){
    peak();
    pop();
    push(4);
    push(5);
    push(6);
    push(7);
    push(7);
    traverse();
    cout<<pop()<<" ";
    cout<<pop()<<endl;
    traverse();
    cout<<"Peek: "<<peak();
    return 0;
}