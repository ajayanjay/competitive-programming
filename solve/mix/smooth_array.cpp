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

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), c(n);
    for (auto& x: a)
    	cin >> x;

    for (auto& x : c)
    	cin >> x;

    vector<ll> dp(n, 0);
    for (int i = 0; i < n; ++i) {
    	dp[i] = c[i];
    	for (int j = 0; j < i; ++j)
    		if (a[j] <= a[i])
    			dp[i] = max(dp[i], dp[j] + c[i]);
    	
    }

    cout << accumulate(all(c), 0) - *max_element(all(dp)) << '\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
