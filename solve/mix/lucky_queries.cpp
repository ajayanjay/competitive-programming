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
    int cnt4, cnt7;
    int best47, best74;
};

struct SegTree {
    int n;
    vector<_t> tree;
    vector<bool> lazy;
    
    SegTree(string& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t l, _t r) {

        if (l.cnt4 == -1) return r;
        if (r.cnt4 == -1) return l;

        return {
            .cnt4 = (l.cnt4 + r.cnt4),
            .cnt7 = (l.cnt7 + r.cnt7),
            .best47 = max(l.best47 + r.cnt7, l.cnt4 + r.best47),
            .best74 = max(l.cnt7 + r.best74, l.best74 + r.cnt4),
        };
    }

    _t make_node(char item) {
        return {
            .cnt4 = (item == '4' ? 1 : 0),
            .cnt7 = (item == '7' ? 1 : 0),
            .best47 = 1,
            .best74 = 1,
        };
    }

    void flip(int v) {
        swap(tree[v].best47, tree[v].best74);
        swap(tree[v].cnt4, tree[v].cnt7);
    }
    
    void build(string& arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void push(int v) {
        if (lazy[v]) {
            flip(v * 2);
            flip(v * 2 + 1);

            lazy[v * 2] = !lazy[v * 2];
            lazy[v * 2 + 1] = !lazy[v * 2 + 1];

            lazy[v] = false;
        }
    }

    void update(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            flip(v);
            lazy[v] = !lazy[v];
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm));
            update(v*2+1, tm+1, tr, max(l, tm+1), r);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }

    // single point update.
    // void update(int node, int start, int end, int position, int newValue) {
    //     if (start == end) tree[node] = make_node(newValue);
    //     else {
    //         int mid = (start + end) / 2;
    //         if (position <= mid)
    //             update(node * 2, start, mid, position, newValue);
    //         else
    //             update(node * 2 + 1, mid + 1, end, position, newValue);

    //         tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    //     }
    // }
    
    _t query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return {
                .cnt4 = -1,
                .cnt7 = -1,
                .best47 = -1,
                .best74 = -1
            };
        if (l == tl && tr == r)
            return tree[v];

        push(v);
        int tm = (tl + tr) / 2;

        return combine(
            query(v*2, tl, tm, l, min(r, tm)), 
            query(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
    }

    void printLazy() {
        for (auto b : lazy) {
            cout << b << ' ';
        } cout << '\n';
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r).best47; }
    int query() { return query(0, n - 1); }

    void update(int l, int r) { update(1, 0, n - 1, l, r); }
};

void solve() {
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    SegTree st(s);

    while (q--) {
    	string x;
    	cin >> x;

    	if (x == "count") {
            cout << st.query() << '\n';
    	} else {
    		int l, r;
    		cin >> l >> r;
            --l, --r;
    		
            st.update(l, r);
            // st.printLazy();
    	}
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
    