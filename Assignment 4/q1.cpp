#include <iostream>
using namespace std;

#define MAX 5   

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        }
        else{
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } 
            else {
                rear++;
            }
            arr[rear] = x;
            cout << x << " inserted into the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue" << endl;
        }
        else{
            cout << arr[front] << " removed from the queue" << endl;

            if (front == rear) { // only one element
                front = -1;
                rear = -1;
            } 
            else {
                front++;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to peek" << endl;
        }
        else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else{
            cout << "Queue elements are : ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;
        cout << "\n--- Queue Menu ---\n";
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
                cout << "Queue is not Empty.\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is not Full.\n";
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