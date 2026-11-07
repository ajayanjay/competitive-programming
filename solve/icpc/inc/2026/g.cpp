#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

vector<int> findTreeCenters(int n, vector<vector<int>>& adj) {
    if (n == 1) return {0};
    
    vector<int> degree(n, 0);
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    
    int processed_nodes = 0;
    while (n - processed_nodes > 2) {
        int leaf_count = q.size();
        processed_nodes += leaf_count;
        for (int i = 0; i < leaf_count; i++) {
            int u = q.front();  
            q.pop();
            for (int v : adj[u]) {
                degree[v]--;
                if (degree[v] == 1) {
                    q.push(v);
                }
            }   
        }
    }
    
    vector<int> centers;
    while (!q.empty()) {
        centers.push_back(q.front());
        q.pop();
    }
    return centers;
}

int dfs(vector<vi> &g, vi &desc, vi &par, int u, int p) {
    int descendant = 1;

    for (auto v : g[u]) {
        if (v != p) {
            par[v] = u;
            descendant += dfs(g, desc, par, v, u);
        }
    }

    desc[u] = descendant;
    return descendant;
}

void bfs(vector<vi> &g, vector<bool> &vis, vi& res, vi & par, int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        u = q.front(); q.pop();
        res.push_back(u);

        for (auto v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                par[v] = u;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vi> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi c = findTreeCenters(n, g);

    vi par(n, c[0]);
    vi desc(n, 0);

    dfs(g, desc, par, c[0], -1);

    vi idx(n);
    for (int i = 0; i < n; ++i)
        idx[i] = i;

    sort(idx.begin(), idx.end(), [&](auto &a, auto &b) {
        return desc[a] < desc[b];
    });

    // for (auto e : desc) {
    //     cout << e << ' ';
    // } cout << '\n';

    // for (auto e : idx) {
    //     cout << desc[e] << ' ';
    // } cout << '\n';

    int s = idx.size() - 1;
    cout << (s * 2) << '\n';
    for (int i = 0; i < s; ++i) {
        int u = idx[i];
        int p = par[u];

        ++u, ++p;

        cout << "M " << u << ' ' << p << '\n';
        cout << "A " << u << '\n';
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