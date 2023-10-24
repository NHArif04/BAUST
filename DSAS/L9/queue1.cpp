#include<iostream>
using namespace std;

int front = -1, rare = -1;
int queue[5];

void enQueue(int value){
    if(front-1==rare){
        cout<<"Full"<<endl;
    }else{
        if(front==-1){
            front++;
        }
        queue[++rare] = value;
    }
}

bool isEmpty(){
    return front==rare==-1;
}

bool isFull(){
    return 
}

int deQueue(){
    if(front==rare==-1){
        cout<<"Empty"<<endl;
        return -1;
    }else{
        return queue[front++];
    }
}

void display(){
    for (size_t i = front; i <= rare; i++){
        cout<<" | "<<queue[i];
    }
}

int main(){
    
    return 0;
}