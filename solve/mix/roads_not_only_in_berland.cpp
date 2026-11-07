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

struct DSU {
    vector<int> parent, sz;
    
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (sz[px] < sz[py]) swap(px, py);
        parent[py] = px;
        sz[px] += sz[py];
        return true;
    }

    int getSize(int x) {
        return sz[find(x)];
    }
    
    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n;
    cin >> n;

    DSU ds(n + 1);
    vector<pii> broken;
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	cin >> u >> v;

    	if (!ds.unite(u, v)) { // if already connected.
    		broken.pb({u, v});
    	}
    }

    if (broken.empty()) {
    	cout << 0;
    	return;
    }

    vi heads;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; ++i ) {
    	int head = ds.find(i);

    	if (!vis[head]) {
    		heads.pb(head);
    		vis[head] = true;
    	}
    }

    // connect heads.
    int t = broken.size();
    cout << t << '\n';

    // heads size should be the same as t.
    int firstHead = heads[0];
    for (int i = 1; i < heads.size(); ++i) {
    	pii brk = broken[i - 1];

    	int secondHead = heads[i];

    	cout << brk.first << ' ' << brk.second << ' ' << firstHead << ' ' << secondHead << '\n';
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
    