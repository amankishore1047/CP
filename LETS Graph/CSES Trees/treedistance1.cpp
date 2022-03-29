#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
vector<int> depth(N, 0);
vector<int> depth2(N, 0);


void dfs(int node, int par = -1) {
    for(auto x : g[node]) {
        if(x == par) continue;
        depth[x] = 1 + depth[node];
        dfs(x, node);
    }
}
void dfs2(int node, int par = -1) {
    for(auto x : g[node]) {
        if(x == par) continue;
        depth2[x] = 1 + depth2[node];
        dfs2(x, node);
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
    int end;
    int max_d = 0;
    for(int i = 1; i <= n; i++) {
    	if(max_d < depth[i]) {
    		max_d = depth[i];
    		end = i;
    	}
    	depth[i] = 0;
    }


    dfs(end);

    int ans = 0;
    int end2;

    for(int i = 1; i <= n; i++) {
    	if(ans < depth[i]) {
    		ans = depth[i];
    		end2 = i;
    	}
    }

    dfs2(end2);

    for(int i = 1; i <= n; i++) {
    	cout << max(depth[i], depth2[i]) << " ";
    }


    cout << endl;

    

    return 0;
}


