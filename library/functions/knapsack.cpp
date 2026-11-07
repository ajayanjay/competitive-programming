#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

int knapsack(vector<int> w, vector<int> v, int n, int weight) {
	// dp[i][w] represents the maximum value when items until i is taken, with total w weight.
	
	vector<vi> dp(n + 1, vi(weight + 1, 0));

	for (int i = 0; i < n; ++i) {
		for (int s = 0; s <= weight; ++s) {
		    if (s < w[i])
		        dp[i + 1][s] = dp[i][s];
		    else
		        dp[i + 1][s] = max(
		            dp[i][s],
		            dp[i][s - w[i]] + v[i]
		        );
		}
	}

	return dp[n][weight];
}

void solve() {
    int n, weight;
    cin >> n >> weight;
    
    vi w(n), v(n);
    for (int i = 0; i < n; ++i) {
    	cin >> w[i] >> v[i];
    }

    cout << knapsack(w, v, n, weight);
}

signed main() {
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
    