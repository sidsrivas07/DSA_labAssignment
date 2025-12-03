#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;

    DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (r[a] < r[b]) {
            swap(a, b);
        }

        p[b] = a;

        if (r[a] == r[b]) {
            r[a]++;
        }

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU d(n);
    int total = 0;

    for (auto &e : edges) {
        if (d.unite(e[1], e[2])) {
            total += e[0];
        }
    }

    cout << total;
}