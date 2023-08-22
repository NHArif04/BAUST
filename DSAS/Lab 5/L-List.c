// linked list => traverse(), search(), creation(), size(), userInput=> searchValue
// Lab report Name: Basic Study of Singly Linked List.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList();
int size();
void traverse();
bool search();



struct node *head = NULL;

int main(){
    createList();
    size();
    traverse();
    search();
    return 0;
}

struct node *createList(){
    struct node *current = NULL;

    int continueAdding = 1;
    while (continueAdding){
        int value;
        printf("Add a new value: ");
        scanf("%d", &value);
        struct node *Node = (struct node *)malloc(sizeof(struct node));
        Node->data = value;
        Node->next = NULL;

        if (head == NULL)        {
            head = Node;
            current = Node;
        }else{
            current->next = Node;
            current = Node;
        }

        printf("Do you want to continue adding?\n1. Yes,\n0. No\n=> ");
        scanf("%d", &continueAdding);
    }
    return head;
}

int size(){
    struct node* Head = head;
    int count = 0;
    while(Head!=NULL){
        count++;
        Head = Head->next;
    }    
    printf("Size of the list is: %d\n",count);
    return count;
}

void traverse(){
    struct node *Head = head;
    printf("Your List is: ");
    while (Head != NULL)
    {
        printf("%d ", Head->data);
        Head = Head->next;
    }
    printf("\n");
}

bool search(){
    int value;
    printf("Insert a value to search: ");
    scanf("%d",&value);
    struct node *Head = head;
    while(Head){
        if(value == Head->data){
            printf("%d Found!\n",value);
            return true;
        }
        Head = Head->next;
    }
    printf("%d Not Found!\n",value);
    return false;
}
