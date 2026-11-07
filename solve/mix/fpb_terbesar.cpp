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

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n);

    int mx = INT_MIN;
    for (auto &e: a) {
    	cin >> e;
    	mx = max(mx, e);
    }

    vi mp(mx + 1, 0);
    for (auto e: a) {
    	++mp[e];
    }

    for (int g = mx; g >= 1; --g) {

    	int cnt = 0;

    	for (int x = g; x <= mx; x += g){
    		cnt += mp[x];
    	}

    	// cout << g << ' ' << cnt << '\n';

    	if (cnt >= m) {
    		cout << g;
    		return;
    	}
    }

    cout << 1;
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
    