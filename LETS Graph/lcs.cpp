#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> parent(N, 0);

void dfs(int node, int par = -1) {
	parent[node] = par;
    for(auto x : g[node]) {
        if(x == par) continue;
        dfs(x, node);
    }
}

vector<int> path(int node) {
	vector<int> v;
	v.push_back(node);
	while(true) {
		if(parent[node] == -1) break;
		v.push_back(parent[node]);
		node = parent[node];
	}
	reverse(v.begin(), v.end());
	return v;
}


int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int x, y; cin >> x >> y;

    dfs(1);

    auto path_x = path(x);
    auto path_y = path(y);

    int len = min(path_x.size(), path_y.size());

    int common = -1;
    for(int i = 0; i < len; i++) {
    	if(path_y[i] != path_x[i]) break;
    	common = path_x[i];
    }

    cout << common << endl;


    return 0;
}