#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long ncr(long long n, long long k){long long res = 1;if (k > n - k)k = n - k;for (int i = 0; i < k; ++i) {res *= (n - i);res /= (i + 1);}return res;}
/*************************************************/

void solve() {
        
      
        
}
/*************************************************/

void precompute() {
    // seive();
    // first_prime();
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
    int tt = 1; 
    // cin >> tt;
    for(int i = 1; i <= tt; ++i) {
        // google(i);
        precompute();
        solve();
    }
}
/*************************************************/