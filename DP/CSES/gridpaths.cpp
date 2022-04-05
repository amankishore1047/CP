#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
	/* Code Area*/
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<int>> dp(n, vector<int> (n));
 
	for(int i = 0; i < n; i++) {
		if(v[0][i] == '.') dp[0][i] = 1;
		else break;
	}	
	for(int i = 0; i < n; i++) {
		if(v[i][0] == '.') dp[i][0] = 1;
		else break;
	}	
	
	for(int i  = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(v[i][j] == '*') continue;
			(dp[i][j] = dp[i-1][j] + dp[i][j-1]) %= mod;;
		}
	}
 
	cout << dp[n-1][n-1] << endl;
 
	/* Code Area*/
	return 0;
}