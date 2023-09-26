#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *CreateNode()
{
    struct Node *head = NULL;
    struct Node *temp, *p;
    int k = 1;
    do{
        temp = malloc(sizeof(struct Node));
        printf("Enter %d Node data -1 to stop : ", k++);
        scanf("%d", &(temp->data));
        if(temp->data==-1)
            break;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            p= temp;
        }
        else 
        {
            p->next = temp;
            p = temp;  
        }
    } while(temp->data!=(-1));
    return head;
}


void traversal(struct Node *ptr)
{
    int count = 0;
    struct Node *temp_ptr = ptr;
    while (temp_ptr != NULL)
    {
        printf("%d-> ", temp_ptr->data);
        temp_ptr = temp_ptr->next;
        count++;
    }
    printf("\nsize = %d \n\n", count);
}


struct Node *Add_Node_to_First(struct Node *head, int data)
{
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    return temp;
}

struct Node *Add_Node_at_Index(struct Node *head, int data, int index)
{
    struct Node *ptr, *p;
    ptr = malloc(sizeof(struct Node));
    p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


void Add_Node_to_Last(struct Node *ptr, int data)
{
    struct Node *temp, *hold_ptr;
    hold_ptr = ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    while (hold_ptr->next != NULL)
    {
        hold_ptr = hold_ptr->next;
    }
    hold_ptr->next = temp;
}


struct Node *delete_first_node(struct Node *head)
{
    printf("\nDeleting First Node : \n");
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *delete_node_at_index(struct Node *head)
{
    int index;
    printf("\nDelete node at index : ");
    scanf("%d", &index);
    struct Node *ptr, *q;
    ptr = head;
    q = head->next;
    int i = 0;

    if(index==0){
        ptr = head;
    head = head->next;
    free(ptr);
    return head;

    }
    while (i < index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    if(q->next== NULL){
        ptr->next = NULL;
        free(q);
    return head;
    }
    ptr->next = q->next;
    free(q);
    return head;
}


struct Node *delete_Last_node(struct Node *head)
{
    printf("\nDeleting node at Last index : \n");
    struct Node *ptr, *q;
    ptr = head;
    q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

int main()
{
    int data1, data2, data3, index;
    
    struct Node *head;
    head = CreateNode();
    traversal(head);

    printf("\nEnter First New node Data : ");
    scanf("%d", &data2);
    head = Add_Node_to_First(head, data2);
    traversal(head);

    printf("\nEnter an Index to add New node : ");
    scanf("%d", &index);
    printf("\nEnter Node Data at [%d]No. Index : ", index);
    scanf("%d", &data3);
    head = Add_Node_at_Index(head, data3, index);
    traversal(head);

    printf("\nEnter New Last node Data : ");
    scanf("%d", &data1);
    Add_Node_to_Last(head, data1);
    traversal(head);


    head = delete_first_node(head);
    traversal(head);

    head = delete_node_at_index(head);
    traversal(head);

    head = delete_Last_node(head);
    traversal(head);

    return 0;
}