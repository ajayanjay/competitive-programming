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

// x: pick first or second, x = true -> pick first.
int mx(vi &d, vector<pii> &f, int e, int n, int x) {
    d[e] = x ? f[e].first : f[e].second;

    if (e == n - 1) {
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mn = min(mn, abs(d[j] - d[i]));
            }
        }

        return mn;
    }

    return max(
        mx(d, f, e + 1, n, 0),
        mx(d, f, e + 1, n, 1)
        );
}

void solve() {
    int n;
    cin >> n;

    vector<pii> f(n);

    for (int i = 0; i < n; ++i) {
        int e, d;
        cin >> e >> d;
        
        f[i].first = min(e, d);
        f[i].second = max(e, d);
    }

    vi d(n, 0);

    cout << max(mx(d, f, 0, n, 0), mx(d, f, 0, n, 1));
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
    