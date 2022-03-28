/* To find number of ways that given coins sum upto sum 's' */

#include<bits/stdc++.h>
using namespace std;


int getcoins(int coins[])

int main() {
    int n; cin >> n;
    int sum; cin >> sum;
    int coins[n];
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int ans = getcoins(coins, n, sum);
    cout << ans << endl;


    return 0;

}