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

vi func(vi &a, int l, int m) {

	if (m < 0) return {};
	if (m == 0) return {l};

	int n = a.size();
	if (l >= n) return {};

	vi res = {l};
	int mn = INT_MAX;
	for (int i = l + 1; i < n; ++i) {

		vi e = func(a, i, m - a[i]);

		if (e.empty()) continue;

		int sz = e.size();
		if (sz < mn) {
			mn = sz;
			res = {l};
			for (auto x : e)
				res.pb(x);
		}
	}

	if (mn == INT_MAX) return {};
	else return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (auto &e: a)
    	cin >> e;

    // returns the index of the item that if the value is combined
    // resulted in m

    // vi res;
    // int mn = INT_MAX;
    // for (int i = 0; i < n; ++i) {
    // 	vi e = func(a, i, m - a[i]);

    // 	if (e.empty()) continue;

    // 	int sz = e.size();
    // 	if (sz < mn) {
    // 		mn = sz;
    // 		res = e;
    // 	}
    // }

    // if (res.empty()) {
    // 	cout << 1 << '\n' << -1;
    // } else {
    // 	cout << mn << '\n';
    // 	for (auto e : res)
    // 		cout << (e + 1) << ' ';
    // }

    vi dp(m + 1, INT_MAX);
    vi parent(m + 1, -1);
    vi prevSum(m + 1, -1);

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
    	for (int s = m; s >= a[i]; --s) {

    		int nxt = s - a[i];
    		if (dp[nxt] == INT_MAX) continue;

    		if (dp[nxt] + 1 < dp[s]) {
    			dp[s] = dp[nxt] + 1;
    			parent[s] = i;
    			prevSum[s] = nxt;
    		}
    	}
    }

    if (dp[m] == INT_MAX) {
    	cout << 1 << '\n' << -1;
    	return;
    }
 	
    int s = m;
    vi res;
    while (s > 0) {
    	int i = parent[s];

    	res.pb(i);
    	s = prevSum[s];
    }

    cout << res.size() << '\n';
    for (auto e: res) {
    	cout << (e + 1) << ' '; 
    }
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
    