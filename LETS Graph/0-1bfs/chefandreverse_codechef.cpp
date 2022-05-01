#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int INF = INT_MAX;
vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m; 

int bfs() {
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop_front();
        for(auto &it : g[node]) {
            int child = it.first;
            int wt = it.second;
            if(level[child] > level[node] + wt) {
                level[child] = level[node] + wt;
                if(wt == 1) q.push_back(child);
                else q.push_front(child);
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(u == v) continue;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }

    cout << bfs() << endl;

    return 0;
}