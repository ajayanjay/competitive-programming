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

    vi a(n);
    for (int i = 0 ; i < n; ++i ) {
    	int x;
    	cin >> x;

    	if (i == 0) a[i] = x;
    	else {
    		a[i] = x + a[i - 1];
    	}
    }

    int q;
    cin >> q;

    while (q--) {
    	int m;
    	cin >> m;

    	int res = lower_bound(all(a), m) - a.begin();

    	cout << (res + 1) << '\n';
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
    