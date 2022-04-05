#include<bits/stdc++.h>
using namespace std;
 
int mod = 1e9 + 7;
 
int dp[102][(int) 1e6 + 5];
 
int recursion (vector<int>& coins, int sum, int n) {
	for(int i = 1; i <= sum; i++) {
		dp[0][i] = INT_MAX;
	}
 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			dp[i][j] = dp[i-1][j];
			if(j - coins[i - 1] >= 0) {
				if(dp[i][j - coins[i-1]] != INT_MAX) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
				}
			}
		}
	}
 
	return dp[n][sum];
 
 
}
int main() {
	/* Code Area*/
 
	int n; cin >> n;
	int x; cin >> x;
 
	vector<int> coins(n);
 
	for(int i  =0; i < n; i++) {
		cin >> coins[i];
	}
 
	int ans = recursion(coins, x, n);
 
 
 
	if(ans == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
 
	cout << ans << endl;
 
 
 
	/* Code Area*/
	return 0;
}