#include <iostream>
using namespace std;
#define MAX 5   

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((rear + 1) % MAX == front);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
        cout << x << " inserted into the queue." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << arr[front] << " removed from the queue." << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % MAX;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to peek." << endl;
        } 
        else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main() {
    CircularQueue q;
    int choice, value;
    cout << "\n--- Circular Queue Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Check if Empty\n";
    cout << "6. Check if Full\n";
    cout << "0. Exit\n";
    do {
       
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is NOT Empty.\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is NOT Full.\n";
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}