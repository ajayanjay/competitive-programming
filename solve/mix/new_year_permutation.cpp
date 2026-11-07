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
    vi a(n);

    for (auto & e : a) {
    	cin >> e;
    }

    vector<string> m(n);
    DSU ds(n);

    for (int i = 0; i < n; ++i) {

    	cin >> m[i];

    	for (int j = 0; j < n; ++j) {
    		char c = m[i][j];

    		if (c == '1') {
    			ds.unite(i, j);
    		}
    	}
    }

    vector<vi> arr(n);
    for (int i = 0; i < n; ++i) {
    	arr[ds.find(i)].pb(i);
    }

    vi res(a);
    for (auto & x : arr) {
    	if (x.empty()) continue;
    	vi prev(x);

    	sort(all(x), [&](auto i, auto j) {
    		return a[i] < a[j];
    	});

    	// x: {0, 1, 5} -> {1, 5, 0}
    	// res[0] = a[1]

    	int sz = x.size();
    	for (int i = 0; i < sz; ++i) {
    		res[prev[i]] = a[x[i]];
    	}
    }

    for (auto e : res) {
    	cout << e << ' ';
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
    