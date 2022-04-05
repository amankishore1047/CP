#include<bits/stdc++.h>
using namespace std;
 
int main() {
	
	int mod = 1e9 + 7;
	int n, sum; cin >> n >> sum;	
	vector<int> coins(n);
	for(auto &x : coins) cin >> x;
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			int left = j - coins[i-1];
			if(left >= 0) (dp[i][j] += dp[i][left]) %= mod;
		}
	}	
	cout << dp[n][sum] << endl;
	return 0;
}