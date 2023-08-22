#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("Linear Search: Element found at index %d.\n", linearResult);
    } else {
        printf("Linear Search: Element not found in the array.\n");
    }

    key = 3;
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d.\n", binaryResult);
    } else {
        printf("Binary Search: Element not found in the array.\n");
    }

    return 0;
}
