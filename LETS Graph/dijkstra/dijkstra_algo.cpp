#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int INF = INT_MAX;

vector<pair<int, int>> g[N];
vector<int> dist (N, INF);
vector<bool> vis(N, 0);

void dijkstra(int source) {
    set<pair<int, int>> st;

    st.insert({0, source});
    dist[source] = 0;

    while(st.size() > 0) {
        auto p = *st.begin();
        int v = p.second;
        int d = p.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto &it : g[v]) {
            int child = it.first;
            int wt = it.second;
            int new_dist = dist[v] + wt;
            if(new_dist < dist[child]) {
                st.insert({new_dist, child});
                dist[child] = new_dist;
            }
        }

    }
}


int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, wt; cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    for(int i = 1; i <= n; ++i) {
        cout << i << " " << dist[i] << "\n";
    }
}