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
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    for (auto &x : a) 
    	for (auto &e : x)
    		cin >> e;

    vll acc(m), prefSum(m), suffSum(m);

    for (int i = 0; i < m; ++i) {
    	ll sum = 0;
    	for (int j = 0; j < n; ++j) {
    		sum += a[j][i];
    	}
    	acc[i] = sum;
    	prefSum[i] = (i == 0) ? acc[i] : prefSum[i - 1] + acc[i]; 
    }

    for (int i = m - 1; i >= 0; --i) {
    	suffSum[i] = (i == m - 1) ? acc[i] : suffSum[i + 1] + acc[i];
    }

    auto midSum = [&prefSum](int l, int r) { return prefSum[r - 1] - prefSum[l]; };

    ll mn = LLONG_MAX;
    for (int i = 0; i < m - 2; ++i) {
    	for (int j = i + 2; j < m; ++j) {
    		ll
    		left = prefSum[i],
    		mid = midSum(i, j),
    		right = suffSum[j];

    		mn = min(mn, max(left, max(mid, right)) - min(left, min(mid, right)));
    	}
    }

    cout << mn;
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
    