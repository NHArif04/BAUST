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