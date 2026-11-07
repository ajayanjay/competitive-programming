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

struct _t {
	int l, r, y;
};

void solve() {
	int n, q;
	cin >> n >> q;

	int mnR = INT_MAX, mxL = INT_MIN;

	while (n--) {
		int l, r, y;
		cin >> l >> r >> y;

		mnR = min(mnR, r);
		mxL = max(mxL, l);
	}

	while (q--) {
		int p;
		cin >> p;

		cout << max(p - mnR, mxL - p) << '\n';
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
    