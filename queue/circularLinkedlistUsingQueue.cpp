#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (front == NULL) {
            front = newNode;
            rear = newNode;
            rear->next = front;   // circular link
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;   // last node points to front
        }

        cout << value << " is inserted into the queue" << endl;
    }

    // Dequeue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;

        // Only one node
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
            rear->next = front;
        }

        cout << temp->data << " is deleted from the queue" << endl;
        delete temp;
    }

    // Peek
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Front element is " << front->data << endl;
        }
    }

    // Display
    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue elements are: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }

    // Is Empty
    void isEmpty() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "Queue is not empty" << endl;
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.peek();

    q.isEmpty();

    return 0;
}