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
    int n , m;
    cin >> n >> m;

 	vector<vi> groups(m);
    DSU ds(n + 1);
 	for (int i = 0; i < m; ++i) {
 		int sz;
 		cin >> sz;

 		vi arr(sz);
        int prev;
 		for (int j = 0; j < sz; ++j) {
            int e;
            cin >> e;
            if (j == 0) {
                prev = e;
            } else {
                ds.unite(prev, e);
                prev = e;
            }

            arr[j] = e;
        }

 		groups[i] = arr;
 	}

    for (int i = 1; i <= n; ++i) {
        cout << ds.getSize(i) << ' ';
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
    