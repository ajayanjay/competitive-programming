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


// where they came from
struct _t {
    char dir;
    bool l = false, r = false, u = false, d = false;
};

// dont think about making money here
// just click backward, thats it
void backward(vector<vector<_t>> &g, vector<vector<bool>> &vis, int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;

    int n = g.size();
    int m = g[0].size();

    _t curr = g[i][j];

    // pick one of the path they came from, however

    if (curr.l) { // if came from left, go left
        backward(g, vis, i, j - 1);
    }

    else if (curr.r) {
        backward(g, vis, i, j + 1);
    }

    else if (curr.u) {
        backward(g, vis, i - 1, j);
    }

    else if (curr.d) {
        backward(g, vis, i  + 1, j);
    }
}

// modify char from [R D L U] to '.'
void forward(vector<vector<_t>> &g, vector<vector<bool>> &vis, int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;

    char curr = g[i][j].dir;
    int n = g.size();
    int m = g[0].size();

    switch (curr) {
    case 'D':
        if (i + 1 < n)
            return forward(g, vis, i + 1, j);
        break;
    case 'R':
        if (j + 1 < m)
            return forward(g, vis, i, j + 1);
        break;
    case 'U':
        if (i - 1>= 0)
            return forward(g, vis, i - 1, j);
        break;
    case 'L':
        if (j - 1 >= 0)
            return forward(g, vis, i, j - 1);
        break;
    }
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);

    for (auto &s : g)
        cin >> s;

    vector<vector<_t>> a(n, vector<_t>(m, {false}));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = g[i][j];
            // cout << c << ' ';

            a[i][j].dir = c;

            // if right, j + 1.l = true

            if (c == 'R' && j + 1 < m) {
                a[i][j + 1].l = true;
            }

            if (c == 'L' && j - 1 >= 0) {
                a[i][j - 1].r = true;
            }

            if (c == 'D' && i + 1 < n) {
                a[i + 1][j].u = true;
            }
 
            if (c == 'U' && i - 1 >= 0) {
                a[i - 1][j].d = true;
            }

        }

        // cout << '\n';
    }
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int res = 0;

    // find all terminal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            _t curr = a[i][j];

            if (!curr.l && !curr.r && !curr.d && !curr.u) {
                // is terminal
                forward(a, vis, i, j);
                ++res;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) { // forward backward spread
                // i fucmign hate this ufkcjng proewrlibnewfouibwuigdwfipgnd
                ++res;
                forward(a, vis, i, j);
            }
        }
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
    