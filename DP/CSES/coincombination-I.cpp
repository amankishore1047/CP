#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
	/* Code Area*/
	
	int n, sum; cin >> n >> sum;
	vector<int> coins(n);
	for(int i = 0; i < n; i++) {
		cin >> coins[i];
	}
 
	vector<int> dp(sum + 1);
	dp[0] = 1;
 
	for(int i = 0; i <= sum; i++) {
		for(int j = 0; j < n; j++) {
			if(i - coins[j] < 0) continue;
			(dp[i] += dp[i - coins[j]]) %= mod;
		}
	}
 
	cout << dp[sum] << endl;
	
	/* Code Area*/
	return 0;
}