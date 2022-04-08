#include<bits/stdc++.h> 
using namespace std;


void testcase() {

	char last1 = '0', last2 = '0';
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'R') {
			if(last1 == '0') last1 = s[i];
			else {
				if(last1 != s[i]) {
					ans++;
					last1 = s[i];
				}
			}
		}
		if(s[i] == 'L') {
			if(last1 == '0') last1 = s[i];
			else {
				if(last1 != s[i]) {
					ans++;
					last1 = s[i];
				}
			}
		}
		if(s[i] == 'U') {
			if(last2 == '0') last2 = s[i];
			else {
				if(last2 != s[i]) {
					ans++;
					last2 = s[i];
				}
			}
		}
		if(s[i] == 'D') {
			if(last2 == '0') last2 = s[i];
			else {
				if(last2 != s[i]) {
					ans++;
					last2 = s[i];
				}
			}
		}

		// cout << last1 << " " << last2 << " " << ans << endl;
	}

	cout << ans + 1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
	int t = 1; 
	// cin >> t;
	while(t--) {
		testcase();
	}
	return 0;
}