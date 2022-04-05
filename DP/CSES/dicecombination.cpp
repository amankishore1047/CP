#include<bits/stdc++.h>
using namespace std;
 
vector<int> dp(1e6+5, 0);
int mod = 1e9 + 7;
 
int recursion(int n) {
	if(n < 0) return 0;
	if(n == 0) return 1;
	if(dp[n] != 0) return dp[n];
	dp[n] = recursion(n-1);
	for(int i = 2; i <= 6; i++) {
		(dp[n] += recursion(n - i)) %= mod;
	}
	return dp[n] % mod;
}
 
int main() {
	/* Code Area*/
 
	int n; cin >> n;
 
	int ans = recursion(n);
 
	cout << ans << endl;
 
 
 
	/* Code Area*/
	return 0;
}