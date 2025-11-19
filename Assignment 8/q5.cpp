#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int i, bool asc) {
    int extreme = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (asc) {
        if (l < n && a[l] > a[extreme]) extreme = l;
        if (r < n && a[r] > a[extreme]) extreme = r;
    } else {
        if (l < n && a[l] < a[extreme]) extreme = l;
        if (r < n && a[r] < a[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(a[i], a[extreme]);
        heapify(a, n, extreme, asc);
    }
}

void heapSort(vector<int>& a, bool asc) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, asc);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, asc);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool asc;
    cin >> asc;
    heapSort(a, asc);
    for (int x : a) cout << x << " ";
}