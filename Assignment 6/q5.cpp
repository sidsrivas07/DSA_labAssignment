#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val = 0, Node* p = nullptr, Node* n = nullptr)
    {
        data = val;
        prev = p;
        next = n;
    }
};

bool checkCLL(Node* head)
{
    Node* current = head;
    while(current != nullptr)
    {
        if(head->prev == current && current->next == head)
        return true;
        current = current->next;
    }
    return false;
}
int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n1;
    n1->prev = n3;

    if (checkCLL(n1))
        cout << "Circular Doubly Linked List";
    else
        cout << "Not Circular";

    return 0;
}