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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    /*
        (a/b) ? (c/d)
        (ad) ? (cb)
    */

    int l = a * d;
    int r = c * b;

    if (l == r) {
        cout << "sama";
    } else if (l > r) {
        cout << "lebih besar";
    } else {
        cout << "lebih kecil";
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
    