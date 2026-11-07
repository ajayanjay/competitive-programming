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

    vi a(n), b(n);
    for (auto &e: a) {
    	cin >> e;
    }

    for (auto &e: b) {
    	cin >> e;
    }

    while (q--) {
    	int t;
    	cin >> t;

    	if (t== 1) {
    		int x, y, k;
    		cin >> x >> y >> k;

    	} else {
    		int x;
    		cin >> x;

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
    