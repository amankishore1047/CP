#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N, 0);

void dfs(int node) {
    vis[node] = 1;
    for(auto x : g[node]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}