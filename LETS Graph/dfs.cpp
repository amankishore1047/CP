// Depth First Search
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
vector<bool> vis(N, 0);
vector<int> store_dfs;

void dfs(int node) {
    vis[node] = 1;
    for(int child : adj[node]) {
        if(vis[child] == 0) {
            store_dfs.push_back(child);
            dfs(child);
        }
        
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            store_dfs.push_back(i);
            dfs(i);
        }
    }

    for(auto it : store_dfs) cout << it << " ";
    cout << endl;

    return 0;    
}