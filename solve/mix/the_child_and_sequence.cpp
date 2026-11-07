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
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto &e: a) {
    	cin >> e;
    }

    while (q--) {
    	int t;
    	cin >> t;
    	if (t == 1) { // print sum [l..r]
    		int l, r;
    		cin >> l >> r;
    		--l, --r;

    	} else if (t == 2) { // i: l..r, a[i] %= x
    		int l, r, x;
    		cin >> l >> r >> x;
    		--l, --r;

    	} else { // a[k] = x
    		int k, x;
    		cin >> k >> x;
    		--k;


    	}
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
    