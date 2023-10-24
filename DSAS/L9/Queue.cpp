#include<iostream>
using namespace std;

int front = -1, rare = -1;
#define Max 5

int queue[Max];

bool isFull(){
    return front == (rare+1)%Max;
}

bool isEmpty(){
    return front == rare == -1;
}

void enQueue(int value){
    if(isFull()){
        cout<<"Overflow!"<<endl;
    }else{
        if(front==-1){
            front++;
        }
        ++rare;
        rare%=Max;
        queue[rare] = value;
    }
}

int deQueue(){
    if(isEmpty()){
        cout<<"Underflow!"<<endl;
        return -1;
    }else{
        if(front==rare){
            int temp = front;
            front = rare = -1;
            return queue[temp];
        }
        //cout<<"Deque-> "<<queue[]
        front++;
        int temp = front%=Max;
        return queue[temp];
    }
}

void display(){
    cout<<front<<"  "<<rare<<endl;
    getchar();
    if(front<rare){
        for (size_t i = front; i%Max <=rare; i++){
            cout<<i%Max<<"->"<<" | "<<queue[i%Max]<<endl;
            if(i==rare)break;
        }
    }else{
        for (size_t i = rare; i%Max <=front; i++){
            cout<<i%Max<<"->"<<" | "<<queue[i%Max]<<endl;
            if(i==front)break;
        }
    }
    cout<<endl;
}

int main(){
    enQueue(5);
    display();
    enQueue(15);
    display();
    enQueue(25);
    display();
    enQueue(35);
    display();
    enQueue(45);
    display();
    deQueue();
    display();
    enQueue(55);
    deQueue();
    display();
    deQueue();
    enQueue(65);
    display();
    enQueue(75);
    display();
    enQueue(85);
    display();
    enQueue(95);
    display();
    return 0;
}