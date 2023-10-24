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
        Node(int data) : data(data), next(nullptr) {}
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
