#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pci pair<char, int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

struct _t {
	int mp[16];
};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(vector<pci>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t a, _t b) {
    	if (a.mp[0] == -1) return b;
    	if (b.mp[0] == -1) return a;

    	_t res = {};
    	for (int i = 0; i < 16; ++i) {
    		res.mp[i] = b.mp[a.mp[i]];
    	}

    	return res;
    }

    _t make_node(pci item) {
        _t res = {};

        if (item.first == 'x') {
        	for (int i = 0; i < 16; ++i) {
				res.mp[i] = i ^ item.second;        		
        	}
        } else {
        	for (int i = 0; i < 16; ++i) {
        		res.mp[i] = (i + item.second) % 16;
        	}
        }

        return res;
    }
    
    void build(vector<pci>& arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // single point update.
    void update(int node, int start, int end, int position, pci newValue) {
        if (start == end) tree[node] = make_node(newValue);
        else {
            int mid = (start + end) / 2;
            if (position <= mid)
                update(node * 2, start, mid, position, newValue);
            else
                update(node * 2 + 1, mid + 1, end, position, newValue);

            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }
    
    _t query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {{-1}};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r).mp[0]; }
    int query() { return query(0, n - 1); }

    void update(int pos, pci newValue) { update (1, 0, n - 1, pos, newValue); }
};

void solve() {
    int n,q;
    cin >> n >> q;

    vector<pci> ops(n);
    for (auto &[c, i]: ops) {
    	cin >> c >> i;
    }

    SegTree st(ops);

    while (q--) {
    	int idx;
    	pci e;

    	cin >> idx >> e.first >> e.second;
    	--idx;

    	st.update(idx, e);
    	cout << st.query() << '\n';
    }
}

int main() {
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
    