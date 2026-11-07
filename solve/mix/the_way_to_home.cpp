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
    int n,d;
    string s;
    cin >> n >> d >> s;

    vi dp(n, INT_MAX);
    dp[0] = 0;
    for (int i =0 ; i < (n - 1); ++i) {
    	if (s[i] == '0') continue;
    	bool f = false;
    	for (int j = 1; j <= d && i + j < n; ++j) {
    		int pos = i + j;
    		if (s[pos] == '0') continue;

    		f = true;

    		dp[pos] = min(dp[i] + 1, dp[pos]);
    	}

    	if (!f) {
    		cout << -1;
    		return;
    	}
    }

    cout << dp[n - 1] << '\n';
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
    