```C
struct Node* createList(int arr[], int size) {
    struct Node *head = NULL;
    struct Node *current = NULL;

    for (int i = 0; i < size; i++) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = arr[i];
        node->next = NULL;

        if (head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }

    return head;
}
```