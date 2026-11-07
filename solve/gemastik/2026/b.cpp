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
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto & e : a) {
        cin >> e;
    }

    while (q--) {
        char o;
        cin >> o;
        if (o == 'P') {
            int l, r, x;
            cin >> l >> r >> x;

            --l, --r;

            for (int i = l; i <= r; ++i) {
                x = max(1LL * 0, x + a[i]);
            }

            cout << x << '\n';

        } else {
            int i, p;
            cin >> i >> p;

            --i;

            a[i] = p;
        }
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
    