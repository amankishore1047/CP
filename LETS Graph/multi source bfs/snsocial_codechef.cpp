#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int INF = INT_MAX;
int val[N][N];
bool vis[N][N];
vector<vector<int>> level(N, vector<int> (N, INF));
int n, m;

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
bool isvalid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}
int bfs() {
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> val[i][j];
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mx == val[i][j]) {
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    } 
    int ans = 0;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int nodex = p.first;
        int nodey = p.second;
        for(auto &it : movements) {
            int x = it.first + nodex;
            int y = it.second + nodey;
            if(isvalid(x, y)) {
                if(vis[x][y]) continue;
                vis[x][y] = 1;
                level[x][y] = level[nodex][nodey] + 1;
                ans = max(ans, level[x][y]);
                q.push({x, y});
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        reset();
        cin >> n >> m;
        cout << bfs() << endl;
    }

    return 0;
}