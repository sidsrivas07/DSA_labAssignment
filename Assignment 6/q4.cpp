#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node* prev;
    Node* next;
    Node(char val = '\0', Node* p = nullptr, Node* n = nullptr)
    {
        data = val;
        prev = p;
        next = n;
    }
};

bool checkPalindrome(Node* head)
{
    if(head == nullptr)
    return true;
    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    Node* right = current;
    Node* left = head;
    while(left != nullptr && right != nullptr)
    {
        if(right->data != left->data)
        return false;
        right = right->prev;
        left = left->next;
    }
    return true;
}
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i<s.size(); i++)
    {
        Node* newNode = new Node(s[i]);

        if(head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    if(checkPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}