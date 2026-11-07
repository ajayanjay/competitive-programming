#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

struct _t {
	bool x; // xor or not
	int v;
};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t a, _t b) {

    	if (a.v == -1) return {
    		.x = !b.x,
    		.v = b.v
    	};

    	if (b.v == -1) return {
    		.x = !a.x,
    		.v = a.v
    	};

        return {
        	.x = !a.x,
        	.v = (a.x ? (a.v ^ b.v) : (a.v | b.v))
        };
    }

    _t make_node(int item) {
        return {
        	.x = false,
        	.v = item
        };
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int position, int newValue) {
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
        if (r < start || end < l) return {0, -1};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    void update(int pos, int val) {
    	update(1, 0, n - 1, pos, val);
    }

    int query(int l, int r) { return query(1, 0, n - 1, l, r).v; }

    int query() {
    	return query(0, n - 1);
    }

    void print() {
    	for (auto &e: tree) {
    		cout << e.v << ' ';
    	} cout << '\n';
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    int sz = 1 << n;
    vi a(sz);
    for (auto &e: a) {
    	 cin >> e;
    }

    SegTree st(a);

    while (q--) {
    	int p, b;
    	cin >> p >> b;

    	--p;

    	st.update(p, b);
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
    