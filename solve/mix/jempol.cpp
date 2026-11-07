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
	int lcm, max;
};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    // if lcm == max, count + 1
    _t combine(_t a, _t b) {

    	if (a.lcm == -1) return b;
    	if (b.lcm == -1) return a;

        return {
        	.lcm = lcm(a.lcm, b.lcm),
        	.max = max(a.max, b.max)
        };
    }

    _t make_node(int item) {
        return {
        	.lcm = item,
        	.max = item
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

    // single point update.
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
        if (r < start || end < l) return {-1};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    _t query(int l, int r) { return query(1, 0, n - 1, l, r); }
    _t query() { return query(0, n - 1); }

    void update(int pos, int newVal) { update(1, 0, n - 1, pos, newVal); }
};

void solve() {
    
    int n;
    cin >> n;
    vi a(n);
    for (auto &e : a) cin >> e;

    SegTree st(a); // lcm st o(log n) lcm query

	int res = n;

	// i < j, q(i, j) lcm == max          
	for (int i = 0; i < n - 1; ++i) {
        int lm = a[i];
        int mx = a[i];
		for (int j = i + 1; j < n; ++j) {
            lm = lcm(lm, a[j]);
            mx = max(mx, a[j]);

            if (lm == mx) ++res;
		}
	}

	cout << res;	

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
    