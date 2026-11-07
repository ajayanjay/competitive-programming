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
    int n, a, b;
    cin >> n >> a >> b;

    vi h(n);
    for (auto & e : h)
    	cin >> e;

    sort(all(h));

    ll res = 0;
    int i;
    for (i = n - 1; i >= (a + b - 1); i -= (a + b)) {
    	for (int j = 0; j < a; ++j) {
    		res += h[i - j];
    	}
    }

    while (i >= 0) {
    	res += h[i];
    	--i;
    }

     cout << res;
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
    