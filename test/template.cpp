#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<bool> prime(N, 1); // this contains weather a number is prime or not.
vector<int> prime1(N); // it contains all the first prime divisor of elements from 0 to 10^6.
double squareroot(double x) { double lo =  0, hi = 1e18; int test = 150; while(test--) { double mid = lo + (hi - lo)/2; if(mid*mid < x) lo = mid; else hi = mid; } return lo; }
double cuberoot(double x) { double lo =  0, hi = 1e18; int test = 150; while(test--) { double mid = lo + (hi - lo)/2; if(mid*mid*mid < x) lo = mid; else hi = mid; } return lo; }
void seive() {prime[0] = prime[1] = 0;for(int i = 2; i < N; ++i) {if(prime[i] == 0 || (long long)i*i >= N) continue;for(int j = i*i; j < N ; j += i) {prime[j] = 0;}}}
void first_prime() {prime1[1] = 1;for(int i = 2; i < N; i++) {if(prime[i] && (long long) i*i < N) {prime1[i] = i;for(int j = i*i; j < N; j += i) {prime1[j] = i;}}}}



/**********************************************************/
void solve() {
    
}

void precompute() {
    seive();
    first_prime();
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
    int tt = 1; 
    // cin >> tt;
    while(tt--) {
        precompute();
        solve();
    }
}
/**********************************************************/