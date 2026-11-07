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

bool possible(vi &a, int target) {
    return false;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (auto &e : a) {
        cin >> e;
    }

    int k = -1;
    int l = 2, r = 3;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (possible(a, m)) { // if possible try lower value.
            k = m;
            r = m - 1;
        } else { // otherwise go higher.
            l = m + 1;
        }
    }

    cout << k;
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
    