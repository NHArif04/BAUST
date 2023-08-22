Absolutely, here's the complete lab report format along with the full code you provided earlier:

---

## Lab Report: Basic Study of Singly Linked List

### Objectives:
1. To understand the concept of a singly linked list.
2. To implement basic operations such as creation, traversal, and searching on a singly linked list.

---

### Introduction:
A singly linked list is a fundamental data structure in computer science, often used to store and manage collections of data. In this lab, we explore the creation of a singly linked list and perform operations like finding the size, traversing elements, and searching for specific values within the list.

---

### Description:
#### Singly Linked List:
A singly linked list is composed of nodes, each containing data and a reference to the next node. The last node's reference points to NULL, indicating the end of the list. Linked lists offer dynamic memory allocation and efficient insertion and deletion of elements.

#### Basic Operations:
1. **Create List**: This operation allows users to input values and creates a singly linked list.
2. **Size**: The size operation calculates and returns the number of nodes in the linked list.
3. **Traverse**: Traverse operation iterates through the list, printing each node's data.
4. **Search**: The search operation prompts for a value and searches for its presence in the linked list.

---

### Code:
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createList();
int size();
void traverse();
bool search();

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

        if (head == NULL) {
            head = Node;
            current = Node;
        } else {
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
```

---

### Output:
```python
Add a new value: 10
Do you want to continue adding?
1. Yes,
0. No
=> 1
Add a new value: 20
Do you want to continue adding?
1. Yes,
0. No
=> 1
Add a new value: 30
Do you want to continue adding?
1. Yes,
0. No
=> 0
Size of the list is: 3
Your List is: 10 20 30
Insert a value to search: 20
20 Found!
```

---

### Discussion:
Singly linked lists are versatile data structures that find applications in various programming scenarios, including database systems and memory management. Through this lab, we have built a strong foundation for further exploration of more advanced linked list operations and their real-world applications.

---