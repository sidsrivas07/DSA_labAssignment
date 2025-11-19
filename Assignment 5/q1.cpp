#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val = 0, Node* n = nullptr)
    {
        data = val;
        next = n;
    }
};
Node* insertAtBeginning(Node* head, int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;                                            
}
Node* insertAtEnd(Node* head, int val)
{
    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(val);
    return head;
}
Node* insertBefore(Node* head, int val, int x)
{
    Node* newnode = new Node(val);
    if(head->data == x)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    while(current->next != nullptr && current->data != x)
    {
       prev = current;
       current = current->next;
    }
    newnode->next = current;
    prev->next = newnode;
    return head;
}
Node* insertAfter(Node* head, int val, int x)
{
    Node* newnode = new Node(val);
    Node* current = head;
    while(current->next != nullptr && current->data != x)
    {
       current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
    return head;
}
Node* deleteFromBeginning(Node* head)
{
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteFromEnd(Node* head)
{
    Node* current = head;
    Node* prev = nullptr;
    while(current->next != nullptr)
    {
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    delete current;
    return head;
}
Node* deleteNode(Node* head, int x)
{
    Node* current = head;
    Node* prev = nullptr;
    while(current->next != nullptr && current->data != x)
    {
        prev = current;
       current = current->next;
    }
    if(current->data == x)
    {
    prev->next = current->next;
    delete current;
    }
    return head;
}
int pos(Node* head, int x)
{
    Node* current = head;
    int count = 0;
    while(current != nullptr && current->data != x)
    {
        count++;
        current = current->next;
    }
    if(current->data == x)
    return ++count;
    else 
    return -1;
}
void print(Node* head)
{
    Node* current = head;
    while(current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
}
int main() {
    cout << "Menu" << endl;
    cout << "1. Insert at beginning" << endl;
   cout << "2. Insert at end" << endl;
   cout << "3. Insert before" << endl;
cout << "4. Insert after" << endl;
cout << "5. Delete from beginning" << endl;
cout << "6. Delete from end" << endl;
cout << "7. Delete from position" << endl;
cout << "8.Return position" << endl;
Node* n1 = new Node(1);
Node* n2 = new Node(2, n1);
Node* n3 = new Node(3, n2);
Node* n4 = new Node(4, n3);
Node* n5 = new Node(5, n4);
Node* head = n5;
int choice;
int value , x;
cout << "Enter choice: " << endl;
cin >> choice;
switch(choice)
{
    case 1:
    cout << "enter value to insert: " << endl;
    cin >> value;
    print(insertAtBeginning(head, value));
    break;
    
    case 2:
    cout << "enter value to insert: " << endl;
    cin >> value;
    print(insertAtEnd(head, value));
    break;
    
    case 3:
    cout << "enter value to insert: " << endl;
    cin >> value;
    cout << "enter position to insert before: " << endl;
    cin >> x;
    print(insertBefore(head, value , x));
    break;
    
    case 4:
    cout << "enter value to insert: " << endl;
    cin >> value;
    cout << "enter position to insert after: " << endl;
    cin >> x;
    print(insertAfter(head, value , x));
    break;
    
    case 5:
     print(deleteFromBeginning(head));
     break;
     
    case 6:
     print(deleteFromEnd(head));
     break;
     
    case 7:
    cout << "enter position to delete: " << endl;
    cin >> x;
    print(deleteNode(head, x));
    break;
    
    case 8:
    cout << "enter element: " << endl;
    cin >> x;
    cout << pos(head, x) << endl;
    break;
    
    default: 
    cout << "Invalid choice";
}
    return 0;
}