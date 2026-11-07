#include <bits/stdc++.h>
using namespace std;

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
