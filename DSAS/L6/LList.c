/**
 ** Report Name: Operation of Linked List
 *
 * creation()
 * display()
 * firstInsertion()
 * insertLast()
 * insertPosition() -> optional
 * deleteFirst()
 * deleteLast()
 * deletePosition() -> optional
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

void createList();
int size();
void traverse();
bool search();
void insertFirst();
void insertLast();
void insertPosition();
void firstDelete();
void lastDelete();
void deletePosition();

struct node *head = NULL;

int main(){
    createList();
    size();
    traverse();
    insertFirst();
    printf("After first insertion ");
    traverse();
    insertLast();
    printf("After last insertion ");
    traverse();
    insertPosition();
    printf("After insertion ");
    traverse();
    search();
    firstDelete();
    printf("After first deletion ");
    traverse();
    lastDelete();
    printf("After last deletion ");
    traverse();
    deletePosition();
    printf("After deletion ");
    traverse();

    return 0;
}

void createList(){
    struct node *temp = NULL;
    while (1){
        int value;
        printf("Add a new value(or -1 to end input): ");
        scanf("%d", &value);

        if (-1 == value) break;

        struct node *Node = (struct node *)malloc(sizeof(struct node));
        Node->data = value;
        Node->next = NULL;

        if (head == NULL){
            head = Node;
            temp = Node;
        }else{
            temp->next = Node;
            temp = Node;
        }
    }
}

int size(){
    struct node *Head = head;
    int count = 0;
    while (Head != NULL){
        count++;
        Head = Head->next;
    }
    printf("Size of the list is: %d\n", count);
    return count;
}

void traverse(){
    struct node *Head = head;
    printf("Your List is: ");
    while (Head != NULL){
        printf("%d ", Head->data);
        Head = Head->next;
    }
    printf("\n");
}

bool search(){
    int value;
    printf("Insert a value to search: ");
    scanf("%d", &value);
    struct node *Head = head;
    while (Head){
        if (value == Head->data){
            printf("%d Found!\n", value);
            return true;
        }
        Head = Head->next;
    }
    printf("%d Not Found!\n", value);
    return false;
}

void insertFirst(){
    int value;
    printf("Input a value to insert at first: ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertLast(){
    int value;
    printf("Input a value to insert last: ");
    scanf("%d", &value);

    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *Head = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    while (Head->next)
        Head = Head->next;

    Head->next = newNode;
}

void insertPosition() {
    int value, position, i;
    printf("Input a value: ");
    scanf("%d", &value);

    printf("Insert at position: ");
    scanf("%d", &position);

    if (position < 1 || position > size() + 1) {
        printf("Invalid position\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    for (i = 2; i < position; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void firstDelete(){
    struct node *temp = head;
    if (temp == NULL){
        printf("List is empty\n");
        return;
    }
    head = head->next;
    free(temp);
}

void lastDelete(){
    struct node *temp = head;
    if (temp == NULL){
        printf("List is empty\n");
        return;
    }
    if (temp->next == NULL){
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deletePosition() {
    int position, i;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > size()) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        firstDelete();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    for (i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}