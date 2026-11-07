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

    int res = 0;
    for (int i = 0; i < n; ++i) {
        char t;
        int x, y;
        cin >> t >> x >> y;

        if (t == 'D') {
            res += (x + y);
        } else if (t == 'A') {
            res += x;
        } else if (t == 'K') {
            res += y;
        }
    }

    cout << (res % 2 == 0 ? "Astik" : "Gema");

    // d -> (x + y) % 2 == 0 ? astik : gema
    // k -> y % 2 == 0 ? astik : gema
    // a -> x % 2 == 0 ? astik : gema

    // 2e5 * 2e9
    // 4e14
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
    