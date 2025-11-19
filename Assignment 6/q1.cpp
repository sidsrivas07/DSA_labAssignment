#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
public:
    Node(int val = 0, Node* p = NULL, Node* n = NULL) {
        data = val;
        prev = p;
        next = n;
    }
};

Node* insertionAtBeginningDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEndDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* insertAfterDLL(Node* head, int val, int x) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next != nullptr && current->data != x) {
        current = current->next;
    }
    if (current->data == x) {
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
    }
    return head;
}

Node* insertBeforeDLL(Node* head, int val, int x) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next != nullptr && current->data != x) {
        current = current->next;
    }
    if (current->data == x) {
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev != nullptr)
            current->prev->next = newNode;
        else
            head = newNode;
        current->prev = newNode;
    }
    return head;
}

Node* deleteNodeDLL(Node* head, int x) {
    if (head == NULL)
        return NULL;
    else if (head->data == x) {
        Node* temp = head;
        if (head->next != nullptr)
            head->next->prev = nullptr;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->data != x) {
            current = current->next;
        }
        Node* temp = current;
        if (current->next == nullptr) {
            current->prev->next = nullptr;
            delete temp;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete temp;
        }
    }
    return head;
}

void searchNodeDLL(Node* head, int x) {
    Node* temp = head;
    bool found = false;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == x) {
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (found)
        cout << "Element " << x << " found at position " << pos << endl;
    else
        cout << "Element not found" << endl;
}

void displayDLL(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertionAtBeginningCLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return head;
    }
    Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
    return head;
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

Node* deleteNodeCLL(Node* head, int x) {
    if (head == NULL)
        return NULL;
    Node* current = head;
    Node* prev = NULL;
    do {
        if (current->data == x)
            break;
        prev = current;
        current = current->next;
    } while (current != head);

    if (current->data != x)
        return head;

    if (current == head && current->next == head) {
        delete current;
        head = NULL;
    } else if (current == head) {
        Node* tail = head->prev;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete current;
    } else {
        prev->next = current->next;
        current->next->prev = prev;
        delete current;
    }
    return head;
}

void searchNodeCLL(Node* head, int x) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    bool found = false;
    int pos = 1;
    do {
        if (temp->data == x) {
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (found)
        cout << "Element " << x << " found at position " << pos << endl;
    else
        cout << "Element not found" << endl;
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
    int choice = 0, val, x, type;

    cout << "1. Doubly Linked List\n2. Circular Linked List\n";
    cout << "Enter type of list: ";

    cin >> type;

    while (!cin || (type != 1 && type != 2)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter 1 for DLL or 2 for CLL: ";
        cin >> type;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Delete node\n6. Search node\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            if (type == 1) headDLL = insertionAtBeginningDLL(headDLL, val);
            else headCLL = insertionAtBeginningCLL(headCLL, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            if (type == 1) headDLL = insertAtEndDLL(headDLL, val);
            else headCLL = insertAtEndCLL(headCLL, val);
            break;
        case 3:
            cout << "Enter value and element after which to insert: ";
            cin >> val >> x;
            headDLL = insertAfterDLL(headDLL, val, x);
            break;
        case 4:
            cout << "Enter value and element before which to insert: ";
            cin >> val >> x;
            headDLL = insertBeforeDLL(headDLL, val, x);
            break;
        case 5:
            cout << "Enter element to delete: ";
            cin >> x;
            if (type == 1) headDLL = deleteNodeDLL(headDLL, x);
            else headCLL = deleteNodeCLL(headCLL, x);
            break;
        case 6:
            cout << "Enter element to search: ";
            cin >> x;
            if (type == 1) searchNodeDLL(headDLL, x);
            else searchNodeCLL(headCLL, x);
            break;
        case 7:
            if (type == 1) displayDLL(headDLL);
            else displayCLL(headCLL);
            break;
        }
        if (type == 1) displayDLL(headDLL);
        else displayCLL(headCLL);
    } while (choice != 8);

    return 0;
}