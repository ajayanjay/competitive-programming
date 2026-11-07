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
    int n, h, w;
    cin >> n >> h >> w;

    vi a(n);
    for (auto &e: a){
    	cin >> e;
    }

    int res = -1;
	int l = 0, r = n - 1;
    while (l <= r) {

    	int m = l + (r - l) / 2;
    	// cout << l << ':' << m << ':' << r << ' ';

    	vector b(a);
    	sort(b.begin(), b.begin() + m + 1);

    	// for (int i = 0; i <= m; ++i) {
    	// 	cout << b[i] << ' ';
    	// } cout << " : ";

    	int i = m;
    	int height = 0;
    	while (i >= 0) {
    		height += b[i];
    		i -= min(i + 1, w);
    	}

    	// cout << curr << '\n';

    	bool possible = height <= h;
    	if (possible) { // possible, try higher value
    		l = m + 1;
    		res = m;
    	} else { // not possible, try lower value
    		r = m - 1;
    	}
    }

    cout << (res + 1);
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
    