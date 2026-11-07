#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define ull unsigned ll

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ull> tun(n, 0);

    while (m--) {
        int x, y, v;
        cin >> x >> y >> v;

        --x, --y;

        ull tx = tun[x];
        ull ty = tun[y];

        tun[x] = ty + v;
        tun[y] = tx + v;
    }

    ull mx = 0;
    for (auto e : tun)
        mx = max(mx, e);

    cout << mx << '\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    