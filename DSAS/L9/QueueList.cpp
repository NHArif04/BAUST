#include<iostream>
using namespace std;

typedef struct{
    int data;
    node* next;
} node;

node* head = nullptr;


void enQueue(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=nullptr;
    if(head!=nullptr){
        head->next = temp;
        head = temp;
        return;
    }
}

void deQueue(){
    cout<<head->data;
    head = head->next;
}

int main(){
    enQueue(5);
    enQueue(15);
    deQueue();
    return 0;
}