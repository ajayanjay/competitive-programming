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
	char l, r;
	int score;
};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(string& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t left, _t right) {

    	if (left.l == 0) {
    		return right;
    	} else if (right.r == 0) {
    		return left;
    	}

        char l = left.r;
        char r = right.l;

        _t res = {
        	.l = left.l,
        	.r = right.r,
        	.score=  left.score + right.score
        };

        if (l == r) {
        	++res.score;
        }

        return res;
    }

    _t make_node(char item) {
        return {
        	.l = item,
        	.r = item,
        	.score = 0
        };
    }
    
    void build(string &arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    _t query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {0, 0, 0};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r).score; }
};

void solve() {
    string s;
    cin >> s;

    SegTree st(s);

    int q; cin >> q;

    while (q--) {
    	int l, r;
    	cin >> l >> r;

    	--l, --r;

    	cout << st.query(l, r) << '\n';

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
    