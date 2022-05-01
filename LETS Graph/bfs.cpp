#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
vector<int> store_bfs;
vector<bool> vis(N,0);
vector<int> level(N);

// NOTE : If the edges are unweighted or the edges have the same weight then the shortest distance 
//        of the node to the root node is the level of that node.

void bfs(int node) {
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while(!q.empty()) {
		node = q.front();
		store_bfs.push_back(node);
		q.pop();
		for(auto it : g[node]) {
			if(!vis[it]) {
				q.push(it);
				vis[it] = 1;
				level[it] = 1 + level[node];
			}
		}
	}
}



int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    for(auto it : store_bfs) cout << it << " ";
    	cout << endl;
    for(int i = 1; i <= n; i++) {
    	cout << i << " - " << level[i] << endl;
    }

    return 0;
}


