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
    vi t(n - 1);
    for (auto &e : t) {
        cin >> e;
    }

    vi prefSumT(t);
    for (int i = 1; i < n - 1; ++i) {
        prefSumT[i] += prefSumT[i - 1];
    }

    vi a(n), b(n);
    for (auto &e : a) {
        cin >> e;
    }

    for (auto & e : b) {
        cin >> e;
    }

    int ans = 0;
    int r = n - 1;
    int l = r - 1;
    while (r >= 0) {
        while (r >= 0 && b[r] <= a[r]) --r;

        if (r < 0) break;
        if (r == 0) { // can't.
            cout << -1;
            return;
        }

        // cout << l << ' ' << r << b[r] << ' ' << a[r] << '\n';
        // r is at place where steak needed to be created.
        int needed = b[r] - a[r];
        l = min(r - 1, l);
        while (l >= 0 && needed > 0) {

            int take = min(needed, a[l]);
            a[l] -= take;
            needed -= take;

            a[r] += take;

            int cost;
            if (l > 0) {
                cost = (prefSumT[r - 1] - prefSumT[l - 1]) * take;
            } else {
                cost = prefSumT[r - 1] * take;                
            }
            ans += cost;

            if (a[l] <= 0) --l;
            // cout << needed << ' ' << l << ":" << r << '\n';
        }

        if (needed > 0) {
            cout << -1;
            return;
        }
    }

    cout << ans;
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
    