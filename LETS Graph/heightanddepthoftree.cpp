#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> height(N, 0);
vector<int> depth(N, 0);

void dfs(int node, int parent = 0) {
    for(auto x : g[node]) {
        if(x == parent) continue;
        depth[x] = depth[node] + 1;
        dfs(x, node);
        height[node] = max(height[node], height[x] + 1);
    }
}


int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
       cout << depth[i] << " " << height[i] << endl;
    }

    return 0;
}