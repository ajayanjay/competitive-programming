#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

#define MOD 1e9 + 7

void solve() {
    int n,k, d;
    cin >> n >> k >> d;

    // sum = n, max = k, min = d
    // how many combination?

    // k = 1, d = 1, n = 5, 
    // 1 1 1 1 1 		k = 1
    // 1 1 1 2 x 4		k = 2
    // 1 2 2 x 3		k = 2
    // 1 1 3 x 3		k = 3
    // 3 2 x 2			k = 3
    // 1 4 x 2			k = 4
    // 5 x 1 			k = 5

    // k = 1, d = 1 -> 1
    // k = 2, d = 1 -> above + (n - 1) + ... + (n - (n / 2))
    // k = 3, d = 1 -> above + sum((n - i) + sum(n - j) (j = 1, (n - i) / 2)) (i = 1, n / 3)
    /*
	
	int sum = 0;
	for (int i = 1; i <= (n / 3); ++i) {
		sum += (n - i);
		for (int j = 1; j <= ((n - i) / 2); ++j) {
			sum += (n - j);
		}
	}

	d = 1
	dp[n][k][d] = sum (n - i + dp[n - i][k - 1][d]) (i = 1..n/k)

	dp[k][d]

	dp[1][1] = 1
	dp[2][1] = dp[1][1] + sum(n - i)(i = 1..n/2)
	dp[3][1] = dp[2][1] + sum(n - i + sum(n - j) (j = 1..(n-i)/2)) (i = 1..n/3)

	suppose func(n, i, x) = sum(n - i)(i = 1..(n/x))
	
	dp[1][2] = 0
	dp[2][2] = dp[1][2] + sum(n - i)(i = 1..n/2)

	dp[k][d] = 0, for all k < d
	dp[k][d] = dp[k - 1][d] + sum(sum(sum(k - d times)))

	dp[k] = 0 for all k < d
	dp[k] = dp[k - 1] + sum(sum(k - d times))
    */

}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    