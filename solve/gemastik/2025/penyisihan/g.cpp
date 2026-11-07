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

#define ui unsigned int
#define ull unsigned ll

void solve() {
    int q;
    ll k;

    cin >> q >> k;

    set<ll> s;

    while (q--) {
    	ll x;
    	cin >> x;

    	if (s.find(x) == s.end()) {
    		s.insert(x);
    	} else {
    		s.erase(x);
    	}

    	ll mn = LLONG_MAX;

    	for (int i = 0; i <= k; ++i) {
    		if (mn == 0) break;

    		
    		for (auto e: s) {

    		}
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
    