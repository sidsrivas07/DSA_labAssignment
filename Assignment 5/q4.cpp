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

Node* reverseList(Node* head)
{
    Node* nextNode = nullptr;
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    return head;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2, n1);
    Node* n3 = new Node(3, n2);
    Node* n4 = new Node(4, n3);
    Node* n5 = new Node(5, n4);
    Node* head = n5;
    cout << "Original list: ";
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
    head = reverseList(head);
    temp = head;
    cout << "Reversed List: ";
    while(temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}