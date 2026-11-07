#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n, k;
    cin >> n >> k;

    // length of n
    // k fair indices

    for (int i = 0; i < k; ++i) {
        cout << 2 << ' ';
    }

    // the rest must averaged to 2.
    int rest = n - k;
    int sum = (n - k) * 2;

    cout << sum << ' ';
    for (int i = k + 1; i < n; ++i) {
        cout << 0 << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "YES\n";
        // else cout << "NO\n";
    }
}