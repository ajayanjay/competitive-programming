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

    int n, m, x;
    cin >> n >> m >> x;

    vi a(n);
    for (auto &e: a) {
        cin >> e;
    }

    vector<char> ops(n - 1);
    for (auto & c : ops ) {
        cin >> c;
    }

    vector<vi>d(n);
    vector<vector<pii>> p(n, vector<pii>(m, {-1, -1}));

    d[0].pb(a[0]);

    for (int i = 1; i < n; ++i) {

        vector<bool> vis(m, false);
        int e = a[i];
        char o = ops[i - 1];

        for (auto v : d[i - 1]) {
            switch (o) {
            case '+': {
                int res = v + e;
                res %= m;
                if (!vis[res]) {
                    vis[res] = true;
                    d[i].pb(res);
                    p[i][res] = {v, '+'};
                }
                break;
            }

            case '*': {
                int res = v * e;
                res %= m;
                if (!vis[res]) {
                    vis[res] = true;
                    d[i].pb(res);
                    p[i][res] = {v, '*'};
                }
                break;
            }
            case '?': {
                int res = v * e;
                res %= m;
                if (!vis[res]) {
                    vis[res] = true;
                    d[i].pb(res);
                    p[i][res] = {v, '*'};
                }

                res = v + e;
                res %= m;
                if (!vis[res]) {
                    vis[res] = true;
                    d[i].pb(res);
                    p[i][res] = {v, '+'};
                }
                break;
            }
            }
        }
    }

    for (auto e : d[n - 1]) if (e == x) {
        vector<char> ans(n - 1);

        int i = n - 1;
        while (i >= 1) {
            ans[i - 1] = p[i][e].second;
            e = p[i][e].first;
            --i;
        }

        cout << "YA" << '\n';

        for (int i = 0; i < n - 1; ++i) {
            cout << ans[i] << ' ';
        }

        return;
    }

    cout << "TIDAK";
}

signed main() {
    // fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    