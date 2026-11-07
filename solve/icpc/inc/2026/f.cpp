#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;

    vector<vi> a(2, vi(n));
    for (int i = 0; i < 2; ++i) {
        for (auto &e: a[i]) {
            cin >> e;
        }
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