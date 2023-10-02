#include<iostream>
#include<cstdlib>
#include<cstdbool>

using namespace std;


struct node{
    int data;
    node* next;
};

node* head=nullptr;

void push(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = head;

    head=temp;
}

bool isEmpty(){
    return head==nullptr? true:false;
}


void pop(){
    if(isEmpty()){
        cout<<"Empty stack"<<endl;
    }else{
        node* temp = (node*)malloc(sizeof(node));
        temp = head;
        
        head=head->next;
        free(temp);
    }
}

void traverse(){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void peak(){
    cout<<head->data<<endl;
}

int main(){
    
    push(5);
    push(4);
    traverse();
    peak();
    pop();
    traverse();
    return 0;
}