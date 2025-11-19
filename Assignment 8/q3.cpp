#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else if (x > root->val) root->right = insertBST(root->right, x);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (!root) return root;
    if (x < root->val) root->left = deleteNode(root->left, x);
    else if (x > root->val) root->right = deleteNode(root->right, x);
    else {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n, x;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }
    int del;
    cin >> del;
    root = deleteNode(root, del);
    inorder(root);
}