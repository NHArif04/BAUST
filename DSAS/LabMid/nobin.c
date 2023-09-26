#include <stdio.h>

void travarse(int arr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_first(int arr[], int *size, int value) {
    for (int i = (*size) - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = value;
}

void insertion_index(int arr[], int *size, int index, int value) {
    for (int i = (*size) - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    travarse(arr, &size);

    ++size;
    int value;
    printf("Enter value to insert first: ");
    scanf("%d", &value);
    insertion_first(arr, &size, value);
    travarse(arr, &size);

    ++size;
    int index, value2;
    printf("Enter index and value: ");
    scanf("%d", &index);
    scanf("%d", &value2);
    insertion_index(arr, &size, index, value2);
    travarse(arr, &size);

    return 0;
}
