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

    string a, b;
    cin >> a; cin >> b;

    int res = 0;
    bool stl = false;

    for (int i =0 ; i < n; ++i) {
        char aC = a[i];
        char bC = b[i];

        if (aC > bC) {
            if (stl) continue;
            else stl = true;
        } else if (aC == bC) {
            if (stl) continue;
            else continue;
        } else {
            if (stl) {
                ++res;
            }
            stl = false;
        }
    }

    cout << res + stl;
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
    