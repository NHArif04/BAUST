# Lab Report: Stack Implementation - Array vs. Linked List

## Objectives:

1. Implement two stack data structures.
2. Analyze their performance and characteristics.
3. Determine the advantages and disadvantages of each implementation.

## Introduction:

This lab explores two implementations of stack data structures: one using an array and the other using a linked list. The primary goals are to understand their behavior, performance, and suitability for various applications.

## Description:

### Array-based Stack:

- **Implementation:** Utilizes a fixed-size array.
- **Characteristics:**
  - Supports stack operations (push, pop, and peek).
  - O(1) time complexity for operations.
  - Limited capacity, potential for stack overflow.
- **Implementation Simplicity:** Straightforward due to a fixed size.

### Linked List-based Stack:

- **Implementation:** Utilizes a dynamic linked list.
- **Characteristics:**
  - Supports stack operations (push, pop, and peek).
  - O(1) time complexity for operations.
  - Dynamically adjusts to the number of elements.
  - Efficient memory usage as memory is allocated as needed.
- **Implementation Complexity:** Slightly more complex due to dynamic sizing.

## Source Code (Array-based Stack):

```cpp
#include <iostream>

using namespace std;

#define MAX_SIZE 100

class ArrayStack {
private:
    int top;
    int stack[MAX_SIZE];

public:
    ArrayStack() { top = -1;}

    bool isEmpty() { return top == -1;}

    bool isFull() { return top == MAX_SIZE - 1;}

    void push(int data) {
        if (!isFull()) {
            stack[++top] = data;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return stack[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return stack[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {top = nullptr;}

    bool isEmpty() {return top == nullptr;}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!isEmpty()) {
            int data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return data;
        } else {
            cout << "Stack underflow!" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

int main(){
    ArrayStack aStack;
    LinkedListStack lStack;

    aStack.push(10);
    aStack.push(20);

    lStack.push(5);
    lStack.push(15);

    cout << "Array-Stack-peek() -> " << aStack.peek() << endl;
    cout << "Linked-List-Stack-peek() -> " << lStack.peek() << endl;

    aStack.pop();
    lStack.pop();

    cout << "Array-Stack-pop() -> " << aStack.pop() << endl;
    cout << "Linked-List-Stack-pop() -> " << lStack.pop() << endl;
    return 0;
}
```

**Output:**

```
Array-Stack-peek() -> 20
Linked-List-Stack-peek() -> 15
Array-Stack-pop() -> 10
Linked-List-Stack-pop() -> 5
```

## Discussion:

- **Array vs. Linked List**:

  - Array-based stack offers simplicity but has a fixed size.
  - Linked List-based stack provides dynamic sizing and efficient memory usage.

- **Performance**:

  - Both implementations achieve O(1) time complexity for stack operations.

- **Memory Usage**:

  - Array-based stack uses a fixed amount of memory.
  - Linked List-based stack dynamically allocates memory as needed, conserving resources.

- **Ease of Implementation**:
  - Array-based stack is simpler to implement due to its fixed size.
  - Linked List-based stack requires slightly more complex memory management.

## Conclusion:

- Choose the array-based stack for simplicity and when a fixed size suffices.
- Opt for the linked list-based stack for dynamic sizing, efficient memory usage, accepting the slightly increased implementation complexity.
