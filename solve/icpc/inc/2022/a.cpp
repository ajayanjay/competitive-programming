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
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (auto &e : a) {
        cin >> e;
    }

    int cnt = 0;
    int mx = -1;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int diff = max(a[i], max(a[j], a[k])) - min(a[i], min(a[j], a[k]));
                int score = a[i] + a[j] + a[k];

                if (diff <= m) {
                    mx = max(mx, score);
                    ++cnt;
                }
            }
        }
    }

    if (mx == -1) {
        cout << -1;
    } else {
        cout << cnt << ' ' << mx;
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
    