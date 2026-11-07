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

    int n, l;
    cin >> n >> l;

    vi a = {l};

    for (int i = 1; i <= n; ++i) {
        int b = i;
        cin >> b;
        --b;

        int e = a[b];
        int h = e / 2;

        a[b] = h;
        a.insert(a.begin() + b + 1, h);
    }

    for (auto e: a)
        cout << e << ' ';
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
    