#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> h;
public:
    void push(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0 && h[(i - 1) / 2] < h[i]) {
            swap(h[i], h[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        int n = h.size(), i = 0;
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;
            if (largest == i) break;
            swap(h[i], h[largest]);
            i = largest;
        }
    }

    int top() {
        if (h.empty()) return -1;
        return h[0];
    }

    bool empty() { return h.empty(); }

    void print() {
        for (int x : h) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap pq;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    pq.print();
    pq.pop();
    pq.print();
    cout << pq.top();
}