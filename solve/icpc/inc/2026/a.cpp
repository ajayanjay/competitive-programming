#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;
    vi a(n); 

    int mx = INT_MIN;
    for (auto &e: a) {
        cin >> e;
        mx = max(mx, e);
    }  

    cout << mx;
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