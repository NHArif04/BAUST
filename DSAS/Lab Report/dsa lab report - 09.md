# Lab Report: Queue Implementation - Array vs. Linked List

## Objectives:

1. Implement queue data structures using an array and a linked list.
2. Compare their performance and characteristics.
3. Analyze the advantages and disadvantages of each implementation.
4. Evaluate the efficiency of enqueue and dequeue operations.

## Introduction:

Implementing queue data structures using array and linked list. The primary objectives are to understand their behaviors, performance, and suitability for various applications.

## Description:
### Array-based Queue:
- **Implementation:** Utilizes a fixed-size array.
- **Characteristics:**
  - Supports queue operations (enqueue and dequeue).
  - O(1) time complexity for enqueue and dequeue operations.
  - Fixed capacity, potential for queue overflow.
- **Implementation Simplicity:** Straightforward due to a fixed size.

### Linked List-based Queue:
- **Implementation:** Utilizes a dynamic linked list.
- **Characteristics:**
  - Supports queue operations (enqueue and dequeue).
  - O(1) time complexity for enqueue and dequeue operations.
  - Dynamically adjusts to the number of elements.
  - Efficient memory usage as memory is allocated as needed.
- **Implementation Complexity:** Slightly more complex due to dynamic sizing.

## Source Code (Combined):
```cpp
#include <iostream>
using namespace std;

#define MAX_SIZE 4

class Queue {
private:
    int frontA, rearA, countA;
    int queueA[MAX_SIZE];

    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}       //Member Initializer
    };
    Node* frontL, * rearL;
    int countL;

public:
    Queue() {
        frontA = rearA = -1;
        countA = 0;
        frontL = rearL = nullptr;
        countL = 0;
    }

    bool isEmptyA() { return countA == 0; }
    bool isFullA() { return countA == MAX_SIZE; }
    bool isEmptyL() { return countL == 0; }

    void enqueueA(int data) {
        if (!isFullA()) {
            rearA = (rearA + 1) % MAX_SIZE;
            queueA[rearA] = data;
            if (frontA == -1) frontA = rearA;
            countA++;
        }
        else cout << "Array Queue Overflow!" << endl;
    }

    int dequeueA() {
        if (!isEmptyA()) {
            int data = queueA[frontA];
            if (frontA == rearA) frontA = rearA = -1;
            else frontA = (frontA + 1) % MAX_SIZE;
            countA--;
            return data;
        }else{
            cout << "Array Queue Underflow!" << endl;
            return -1;
        }
    }

    void enqueueL(int data) {
        Node* newNode = new Node(data);
        if (isEmptyL()) {
            frontL = rearL = newNode;
        }else{
            rearL->next = newNode;
            rearL = newNode;
        }
        countL++;
    }

    int dequeueL() {
        if (!isEmptyL()) {
            int data = frontL->data;
            Node* temp = frontL;
            frontL = frontL->next;
            if (!frontL) rearL = nullptr;
            delete temp;
            countL--;
            return data;
        }else{
            cout << "Linked-list Queue Underflow!" << endl;
            return -1;
        }
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; i++) {
        q.enqueueA(i * 10);
        q.enqueueL(i * 10);
    }
    cout << "Array Queue Dequeue: ";
    while (!q.isEmptyA()) {
        cout << q.dequeueA() << " ";
    }
    cout << endl << endl;
    cout << "List Queue Dequeue: ";
    while (!q.isEmptyL()) {
        cout << q.dequeueL() << " ";
    }
    cout << endl << endl;
    return 0;
}
```

## Sample Output:
```python
Array Queue Overflow!
Array Queue Dequeue: 10 20 30 40 

List Queue Dequeue: 10 20 30 40 50 
```

## Discussion:
- **Array vs. Linked List**:
  - Array-based queue offers simplicity but has a fixed size.
  - Linked List-based queue provides dynamic sizing and efficient memory usage.
- **Performance**:
  - Both implementations achieve O(1) time complexity for enqueue and dequeue operations.
- **Memory Usage**:
  - Array-based queue uses a fixed amount of memory.
  - Linked List-based queue dynamically allocates memory as needed, conserving resources.

## Conclusion:

- Choose the array-based queue for simplicity and when a fixed size suffices.
- Opt for the linked list-based queue for dynamic sizing, efficient memory usage, accepting the slightly increased implementation complexity. Both implementations offer efficient O(1) time complexity for enqueue and dequeue operations.