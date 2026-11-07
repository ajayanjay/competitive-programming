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

pii create(vector<vi> &g, vector<bool> &vis, vi &h, int u) {
    if (vis[u]) return {h[u], 1};
    vis[u] = true;

    int mn = h[u];
    int sz = 1;
    for (auto v : g[u]) {
        if (!vis[v]) {
            auto [e, s] = create(g, vis, h, v);
            mn = min(mn, e);
            sz += s;
        }
    }

    return {mn, sz};
}

void solve() {
    int n, k, b;
    cin >> n >> k >> b;

    int mn = INT_MAX;
    vi h(n);
    for (auto & e : h) {
        cin >> e;
        mn = min(mn, e);
    }

    vector<vi> g(n);
    for (int i = 0; i < k; ++i) {
        int p, q;
        cin >> p >> q;

        --p, --q;

        g[p].pb(q);
        g[q].pb(p);
    }

    // b only needs to connect smallest val to all possible section

    vector<bool> vis(n, false);
    vector<pii> t;
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            t.pb(create(g, vis, h, i));
    }

    // t is now a vector of {size of group, and the min}

    // we now need to connect b amount of mn into the element of t
    // with the biggest impact -> max (prevVal - newVal)
    // prevVal uses the min of previous, and newVal uses the min of mn
    // val = size * min

    sort(all(t), [&](pii a, pii b){
        int aPrev = a.first * a.second;
        int aNew = mn * a.second;
        int aDiff = aPrev - aNew;

        int bPrev = b.first * b.second;
        int bNew = mn * b.second;
        int bDiff = bPrev - bNew;

        return aDiff < bDiff;
    });

    // now that it's all sorted. we can apply b amount of mn to t.
    int x = t.size();
    for (int i = x - 1; i >= 0 && b > 0; --i, --b) {
        t[i].first = mn;
    }

    // and then get the val.
    int res = 0;
    for (auto [e, s] : t) {
        res += e * s;
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
    