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

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(Node* root) {
    if (!root) return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    int n, x;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }
    cout << countNodes(root) << " " << sumNodes(root);
}