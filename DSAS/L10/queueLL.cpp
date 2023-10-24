#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = nullptr;

void enqueue(int d){
    node *k;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;

    if(head==nullptr){
        head=newNode;
    }else{
        for(k=head; k->next != head; k=k->next){
            k->next = newNode;
        }
    }
}

void dequeue(){
    int i;
    i = head->data;

    if(nullptr==head){
        cout<<"under follow"<<endl;
        return;
    }else{
        node* temp = head;
        if(head->next == head){
            head = nullptr;
            free(temp);
        }else{
            while(temp->next != head){
                temp->next = head->next;
                head = head->next;
                free(temp);
                temp = temp->next;
            }
        }
    }
}

void display(){
    node* temp = head;
    cout<<"queue is: ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp == head) break;
    }
    cout<<endl;
}


int main(){
    enqueue(5);
    display();
    enqueue(7);
    display();
    enqueue(8);
    display();
    enqueue(9);
    display();
    enqueue(1);
    display();

    return 0;
}