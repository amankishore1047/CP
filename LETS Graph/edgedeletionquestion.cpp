// Que : Delete an edge from the given tree such that the product of the values os sum of two trees is maximum.
// Link to problem : 	https://www.interviewbit.com/problems/delete-edge/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<int> subarr_sum(N, 0);
vector<int> a(N);

void dfs(int node, int par = -1) {
    for(auto x : g[node]) {
        if(x == par) continue;
        dfs(x, node);
        subarr_sum[node] += subarr_sum[x];
    }
}



int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	subarr_sum[i+1] = a[i];
    }

    dfs(1);

    int ans = 1;

    for(int i = 1; i <= n; i++) {
    	int p1 = subarr_sum[i];
    	int p2 = subarr_sum[1] - subarr_sum[i];
    	ans = max(ans, (p1*p2));
    }    

    cout << ans << endl;

    return 0;
}