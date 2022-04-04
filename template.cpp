#include<bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 10;
int mod = 1e9 + 7;
int modpow(int x, int n, int m = mod) { // modpow function calculates x^n in just log(n) time. 
	if(n == 0) return 1 % m;
	long long u = modpow(x, n/2, m);
	u = (u*u) % m;
	if(n & 1) u = (u*x) % m;
	return u;
}
bool isprime(int n) {
    if(n == 1) return false;
    for(int i = 0; i*i <= n; i++) {
        if(n % i == 0) {
            // if n is divided by i n is not prime
            return false;
        }
    }
    // no integer from 2 ti n - 1 divides n so n is prime
    return true;
}
vector<bool> prime(N, 1); // prime[i] will return true if i is prime
vector<int> fprime(N, 0); // fprime[i] contains the first prime factor of i 
void seive() {
    prime[0] = prime[1] = 0;
    fprime[0] = fprime[1] = -1;
    for(long long i = 2; i < N; i++) {
        if(prime[i]) {
            // mark all multiples of a prime as composite
            fprime[i] = i;
            for(long long j = i*i; j < N; j += i) {
                prime[j] = 0;
                // if fprime[j] == 0 means av tk koi v prime factor nhi mila 
                if(fprime[j] == 0) fprime[j] = i;
            }
        }
    }
}
vector<int> primefactorization(int n) {
	vector<int> v;
	while(n > 1) {
		int x = fprime[n]; // find the smallest prime of n
        // divide it untill it is divisible by smallest prime factor of n and keep adding x to the prime factorization factor vector v.
		while(n % x == 0) {
			v.push_back(x);
			n /= x;
		}
	}
	return v;
}


void solve () {
	
	for(int i = 2; i < 101; i++) {
		cout << i << " - " << fprime[i] << endl;
	}

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);  cout.tie(NULL);
	int t = 1; 
	// cin >> t;
	seive();
	while(t--) {
		solve();
	}
	return 0;
}