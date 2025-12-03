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
    }

    int src;
    cin >> src;

    const int INF = 1000000000;
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        pq.pop();

        int d = temp.first;
        int x = temp.second;

        if (d != dist[x]) continue;

        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first;
            int w = g[x][i].second;

            if (dist[y] > d + w) {
                dist[y] = d + w;
                pq.push(make_pair(dist[y], y));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}