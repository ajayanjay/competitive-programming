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
    ll n, m;
    cin >> n >> m;

    if (m == 0) {
    	cout << n << '\n';
    	return;
    }
    
    ll l = n - m;
    if (l < 0) l = 0;
    ll r = n + m;

    ll i = 1;

    ll res = n | l | r;
    bool handled;
    while (1) {
    	handled = false;
    	if ((l + i) <= n) {
    		res |= (l + i);
    		handled = true;
    	}

    	if ((r - i) >= n) {
    		res |= (r - i);
    		handled = true;
    	}

    	if (!handled) break;

    	i *= 2;
 	}

    cout << res << '\n';
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
    