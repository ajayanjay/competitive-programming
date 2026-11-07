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
    int n;
    cin >> n;

    vi b(n), j(n);
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;

        mn = min(mn, e);
        b[i] = mn;
    }

    for (int i = 0; i < n; ++i) {
        cin >> j[i];
    }

    if (n < 3) {
        cout << "tidak mungkin";
        return;
    }

    int mx = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
        mx = max(mx, j[i]);
        j[i] = mx;
    }

    int res = INT_MIN;
    for (int i = 0; i < n - 2; ++i) {
        res = max(res, j[i + 2] - b[i]);
    }

    if (res <= 0) {
        cout << "tidak mungkin";
    } else {
        cout << res;
    }


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
    