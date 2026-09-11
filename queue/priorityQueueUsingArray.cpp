#include <iostream>
using namespace std;

class priorityQueue {
    int arr[100];
    int size;

public:
    priorityQueue() {
        size = 0;
    }

    void enqueue(int value) {
        if (size >= 100) {
            cout << "Queue is full" << endl;
            return;
        }

        int i = size - 1;
        while (i >= 0 && arr[i] > value) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = arr[0];
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
        return value;
    }

    int peek() const {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == 100;
    }
};

int main() {
    priorityQueue pq;
    pq.enqueue(20);
    pq.enqueue(50);
    pq.enqueue(60);

    cout << pq.dequeue() << endl; // 10
    cout << pq.peek() << endl;    // 20

    return 0;
}
