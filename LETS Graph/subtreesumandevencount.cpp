#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> subtreeSum(N, 0);
vector<int> evenCount(N, 0);

void dfs(int node, int parent = 0) {
    for(auto x : g[node]) {
        if(x == parent) continue;
        dfs(x, node);
        subtreeSum[node] += subtreeSum[x];
        evenCount[node] += evenCount[x];
    }
}


int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if((i & 1) == 0) {
            evenCount[i] = 1;
        }
        subtreeSum[i] = i;
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
       cout << subtreeSum[i] << " " << evenCount[i] << endl;
    }

    return 0;
}