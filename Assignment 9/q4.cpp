#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    vector<int> vis(n, 0);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push(make_pair(0, 0));

    int total = 0;

    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        pq.pop();

        int w = temp.first;
        int x = temp.second;

        if (vis[x]) continue;

        vis[x] = 1;
        total += w;

        for (int i = 0; i < g[x].size(); i++) {
            int nx = g[x][i].first;
            int nw = g[x][i].second;
            if (!vis[nx]) {
                pq.push(make_pair(nw, nx));
            }
        }
    }

    cout << total;
}