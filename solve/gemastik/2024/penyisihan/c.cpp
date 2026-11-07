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

void dfs(vector<vi> &g, vector<bool>& vis, int u) {
    if (vis[u]) return;
    vis[u] = true;

    for (auto v: g[u]) {
        if (!vis[v])
            dfs(g, vis, v);
    }
 }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> g(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        g[x].pb(y);
        g[y].pb(x);

        vis[x] = true;
        vis[y] = true;
    }

    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++cnt;
        }
        vis[i] = !vis[i];
    }

    for (int i =0 ; i < n; ++i) {
        if (!vis[i]) {
            ++res;
            dfs(g, vis, i);
        }
    }

    if (cnt > 1) {
        ++res;
    } else if (n == 1) {
        ++res;
    }

    cout << res;
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
    