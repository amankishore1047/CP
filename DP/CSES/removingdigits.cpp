#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int dp[(int)(1e6 + 5)];
 
int recursion(int n) {
	if(n <= 0) return 0;
	int x = n;
	int ans = 1e9;
	if(dp[n] != 0) return dp[n];
	while ( x > 0) {
		int y = x % 10;
		x /= 10;
		if(y == 0) continue;
   	    ans = min(ans, 1+recursion(n-y));
	}
	return dp[n] = ans;
}
 
 
int main() {
	/* Code Area*/
	
	int n; cin >> n;
	int ans = recursion(n);
	cout << ans << endl;
 
	/* Code Area*/
	return 0;
}