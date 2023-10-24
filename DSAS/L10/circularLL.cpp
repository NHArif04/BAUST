#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node{
    int data;
    node* next;
};

node* head = nullptr;

void display();
void dequeue();
void enqueue(int);



int main(){
    enqueue(5);
    display();
    return 0;
}

void display(){
    node* Head = head;
    cout<<"Your Queue is: ";
    while (Head != NULL)
    {
        cout<<Head->data;
        Head = Head->next;
    }
    cout<<endl;
}

void enqueue(int value){
    node *Head = head;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    while (Head->next)
        Head = Head->next;

    Head->next = newNode;
}

void dequeue(){
    node *temp = head;
    if (temp == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    head = head->next;
    free(temp);
}