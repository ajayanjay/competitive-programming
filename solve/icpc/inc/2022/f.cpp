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
    int n, p0, x;
    cin >> n >> p0 >> x;

    vi d(n);
    int sm = 0;
    for (auto &e : d)  {
        cin >> e;
        sm += e;
    }

    vi p(n);
    p[0] = p0;
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1] + d[i - 1];
    }

    int sb = -sm;
    int mn = -1;
    int mnDiff = INT_MAX;
    for (auto e : p) {
        // e, x, sm
        // subtract e with sm until e is nearest to x
        // find smallest such nearest e.

        if (e < x) continue;

        int res = (e - x) % sb + x; 
        int diff = abs(res - x);

        // cout << res << ' ';

        if (diff < mnDiff && x <= res) {
            mn = res;
            mnDiff = diff;
        }
        // e % sm ? 
    }

    cout << mn;
}

signed main() {
    // fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    