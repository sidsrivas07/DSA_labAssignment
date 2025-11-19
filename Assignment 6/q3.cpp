#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val = 0, Node* p = NULL, Node* n = NULL) {
        data = val;
        prev = p;
        next = n;
    }
};

Node* insertAtEndDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int sizeOfDLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayDLL(Node* head) {
    if (head == NULL) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertAtEndCLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return head;
    }
    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

int sizeOfCLL(Node* head) {
    if (head == NULL)
        return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void displayCLL(Node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* headDLL = NULL;
    Node* headCLL = NULL;
    int choice, val, type;

    cout << "1. Doubly Linked List\n2. Circular Linked List\n";
    cout << "Enter type of list: ";
    cin >> type;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Find size of list\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            if (type == 1)
                headDLL = insertAtEndDLL(headDLL, val);
            else
                headCLL = insertAtEndCLL(headCLL, val);
            break;

        case 2:
            if (type == 1)
                displayDLL(headDLL);
            else
                displayCLL(headCLL);
            break;

        case 3:
            if (type == 1)
                cout << "Size of Doubly Linked List = " << sizeOfDLL(headDLL) << endl;
            else
                cout << "Size of Circular Linked List = " << sizeOfCLL(headCLL) << endl;
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}