#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N, 0);

bool dfs(int node, int parent) {
    vis[node] = 1;
    bool isLoopExists = 0;
    for(auto x : g[node]) {
        if(vis[x]) {
            if(x == parent) continue;
            else return true;
        }       
        else {
            isLoopExists |= dfs(x, node);
        }
    }
    return isLoopExists;
}


int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ok |= dfs(i, 0);
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}