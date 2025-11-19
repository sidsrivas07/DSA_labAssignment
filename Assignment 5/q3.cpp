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
int main()
{
    Node* n0 = new Node(0);
    Node* n1 = new Node(1, n0);
    Node* n2 = new Node(2, n1);
    Node* n3 = new Node(3, n2);
    Node* n4 = new Node(4, n3);
    Node* n5 = new Node(5, n4);
    Node* head = n5;
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr) // this returns the second middle node in case of even number of nodes. if i want first middle element then i have to write the condition fast->next != nullptr && fast->next->next != nullptr
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element is: " << slow->data;
    return 0;
}