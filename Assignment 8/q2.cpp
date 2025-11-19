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

Node* searchRec(Node* root, int x) {
    if (!root || root->val == x) return root;
    if (x < root->val) return searchRec(root->left, x);
    return searchRec(root->right, x);
}

Node* searchItr(Node* root, int x) {
    while (root) {
        if (root->val == x) return root;
        root = (x < root->val) ? root->left : root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* successor(Node* root, int key) {
    Node* succ = nullptr;
    while (root) {
        if (key < root->val) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* predecessor(Node* root, int key) {
    Node* pred = nullptr;
    while (root) {
        if (key > root->val) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    int n, x;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }
    int key;
    cin >> key;
    cout << (searchRec(root, key) ? "Found\n" : "Not Found\n");
    cout << findMin(root)->val << " " << findMax(root)->val << "\n";
    Node* s = successor(root, key);
    Node* p = predecessor(root, key);
    if (s) cout << s->val << " "; else cout << -1 << " ";
    if (p) cout << p->val; else cout << -1;
}