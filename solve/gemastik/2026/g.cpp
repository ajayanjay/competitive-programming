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
    int n, k;
    cin >> n >> k;

    vi m(n);
    for (auto &e : m) {
        cin >> e;
    }

    sort(all(m));

    if (n < 3) {
        cout << "TIDAK";
        return;
    }

    int a = m[n - 3];
    int b = m[n - 2];
    int c = m[n - 1];

    int sm = 0;
    for (int i = 0; i < n - 3; ++i) {
        sm += m[i];
    }

    if (c < k) {
        sm -= (k - c);
    }

    if (b < k) {
        sm -= (k - b);
    }

    if (a < k) {
        sm -= (k - a);
    }


    if (sm < 0 ) {
        cout << "TIDAK";
    } else {
        cout << "YA";
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
    