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
    int q, k;
    cin >> q >> k;
    set<int> s;
    while (q--) {
    	int x;
    	cin >> x;

    	if (s.find(x) != end(s)) {
    		s.erase(x);
    	} else {
    		s.insert(x);
    	}
    }

    for (int i = 0; i <= k; ++i) {
		cout << i << ": ";

		for (auto e : s)
			cout << (e ^ i) << ' ';
		cout << '\n';
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
