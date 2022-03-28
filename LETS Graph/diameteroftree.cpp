#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> depth(N, 0);

void dfs(int node, int parent = 0) {
    for(auto x : g[node]) {
        if(x == parent) continue;
        depth[x] = depth[node] + 1;
        dfs(x, node);
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

    int max_d = -1;
    int max_d_element;

    for(int i = 1; i <= n; i++) {
        if(depth[i] > max_d) {
            max_d = depth[i];
            max_d_element = i;
        }
        depth[i] = 0;
    }

    dfs(max_d_element);
    max_d = -1;
    int max_d_element2;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > max_d) {
            max_d = depth[i];
            max_d_element2 = i;
        }
        depth[i] = 0;
    }

    cout << max_d << " " << max_d_element << " " << max_d_element2 << endl;


    return 0;
}