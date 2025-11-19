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
    Node* n1 = new Node(1);
    Node* n2 = new Node(2, n1);
    Node* n3 = new Node(1, n2);
    Node* n4 = new Node(4, n3);
    Node* n5 = new Node(5, n4);
    Node* n6 = new Node(1, n5);
    Node* head = n6;
    int count = 0; 
    Node* current = head;
    Node* prev = NULL;
    Node* temp = nullptr;
    cout << "Enter value to count and delete: " << endl;
    int val;
    cin >> val;
    while(current!=nullptr)
    {
        if(current->data == val)
        {
            count++;
            temp = current;
            if(current == head)
            {
                head = head->next;
                current = head;
            }
            else
            {
                prev->next = current->next;
                current = current->next;
            }
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    cout << "Count: " << count << endl;
    current = head;
    while(current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
}