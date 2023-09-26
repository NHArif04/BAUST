#include<iostream>
#include<cstdbool>
#include<cstdlib>

using namespace std;

struct node{
    int data;
    node* next;
};

node* createList();
int size();
void traverse();
bool search();
void firstInsert();
void lastInsert();
void positionInsert();
void firstDelete();
void lastDelete();
void positionDelete();

node* head = nullptr;

int main(){
    createList();
    size();
    traverse();
    search();
    positionInsert();
    traverse();
    positionDelete();
    traverse();
    return 0;
}

node* createList(){
    node* current = nullptr;


    while(1){
        cout<<"New Value(-1 to end adding): ";
        int value;
        cin>>value;
        if(value==-1) break;
        node* Node = (node*)malloc(sizeof(node));
        Node->data=value;
        Node->next=nullptr;
        if(head == nullptr){
            head = Node;
            current = Node;
        }else{
            current->next = Node;
            current = Node;
        }
    }
    return head;
}

void traverse(){
    node* Head = head;
    cout<<"Your list is: ";
    while(Head){
        cout<<Head->data <<"-> ";
        Head = Head->next;
    }
    cout<<endl;
}

int size(){
    int len=0;
    node* Head = head;
    while(Head){
        Head = Head->next;
        len++;
    }
    cout<<"List size: "<<len<<endl;
    return len;
}

bool search(){
    int value;
    cout<<"Insert a value to search in list: ";
    cin>>value;
    node* Head = head;
    while(Head){
        if(value==Head->data){
            cout<<"Found : "<<value<<endl;
            return true;
        }
        Head = Head->next;
    }
    cout<<"Not Found : "<<value<<endl;
    return false;
}


void positionInsert(){
    int value, position;
    cout<<"Input a value to insert: ";
    cin>>value;
    cout<<"Input position: ";
    cin>>position;

    if(position<1 || position>size()+1){
        cout<<"Invalid position"<<endl;
        return;
    } 

    node* Node;
    Node->data = value;

    if(position==1){
        Node->next = head;
        head = Node;
        return;
    }

    node* Head = head;
    for(int i =2; i<=position; i++){
        Head = Head->next;
    }
    Node->next = Head;
    Head = Node;
    
    traverse();
}

void positionDelete(){
    int position;
    cout<<"Enter position to delete: ";
    cin>>position;

    if(position<1 || position>size()){
        cout<<"Invalid position"<<endl;
        return;
    }

    if(position == 1){
        head = head->next;
        return;
    }

    node* Head = head;
    node* prev = nullptr;

    for(int i=1; i<position; i++){
        prev = Head;
        Head = Head->next;
    }

    prev->next = Head->next;
    free(Head);

    traverse();
}