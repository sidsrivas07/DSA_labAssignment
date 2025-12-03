#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> g(n);
    while(m--) {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src; 
    cin >> src;
    vector<int> vis(n,0);
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()) {
        int x=q.front(); 
        q.pop();
        cout<<x<<" ";
        for(int y:g[x]) if(!vis[y]) vis[y]=1, q.push(y);
    }
}