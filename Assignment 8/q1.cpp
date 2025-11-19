#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& a) {
    if (a.empty() || a[0] == -1) return nullptr;
    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < a.size()) {
        Node* cur = q.front();
        q.pop();
        if (i < a.size() && a[i] != -1) {
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;
        if (i < a.size() && a[i] != -1) {
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Node* root = build(a);
    preorder(root); cout << "\n";
    inorder(root); cout << "\n";
    postorder(root); cout << "\n";
}