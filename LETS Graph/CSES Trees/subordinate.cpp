#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
vector<int> sub(N, 0);
 
 
void dfs(int node, int par = -1) {
    for(auto x : g[node]) {
        if(x == par) continue;
        dfs(x, node);
        sub[node] += (1 + sub[x]);
    }
}
 
 
 
int main() {
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        int u, v; cin >> v;
        u = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
    // sub[1] = n-1;
    for(int i = 1; i <= n; i++) {
    	cout << sub[i] << " ";
    }
    cout << endl;
    
 
    return 0;
}