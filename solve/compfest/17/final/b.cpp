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

#define MD 998244353

struct SegTree {
    int n;
    vector<int> tree;
    
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int combine(int a, int b) {
        return a + b;
    }

    int make_node(int item) {
        return item;
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
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int query() { return query(0, n - 1); }

    void update(int pos, int newVal) { update(1, 0, n - 1, pos, newVal); }

    int getArrSize() {return n;}
};

void dfs(vi &a, vi& b, vector<pii> &at, vector<bool> &vis, int u, int it, int i, vi& t) {
    if (vis[u]) return;
    vis[u] = true;

    // cout << u << '\n';

    at[u] = {it, i};
    t.pb(b[u]);

    int v = a[u];
    dfs(a, b, at, vis, v, it, i + 1, t);
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    vector<bool> isTerminal(n, true);
    for (auto &e : a) {
        cin >> e;
        --e;

        isTerminal[e] = false;
    }

    vi b(n);
    for (auto &e : b) {
        cin >> e;
    }

    // cout << "Checkpoint 1" << '\n';

    // is terminal is used to get the highway to the loop.
    
    // at <segment tree, index>
    vector<pii> at(n, {-1, -1});
    vector<bool> vis(n, false);
    vector<SegTree> sts;
    int it = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;

        vi t;
        dfs(a, b, at, vis, i, it, 0, t);
        // for (auto e : t) {
        //     cout << e << ' ';
        // } cout << '\n';
        sts.pb(SegTree(t));
        ++it;
    }

    // cout << "Checkpoint 2" << '\n';

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, k;
            cin >> x >> k;
            --x;

            pii on = at[x];
            cout << on.first << '-' << on.second << '\n';
            SegTree st = sts[on.first];
            int start = on.second;

            int base = b[x];
            int loop;
            int remaining;

            int loopSize = st.getArrSize();
            int loopAmount = k / loopSize;

            if (k < loopSize) loop = 0;
            else {
                int sz = st.query();
                loop = sz * loopAmount;
            }

            // remaining -> query from start to start + k % loopSize

            int length = k % loopSize;
            // start to start + length

            if (start + length < loopSize) { // still within boundary
                int sz = st.query(start, start + length);
                remaining = sz;
            } else {
                int sz1 = st.query(start, loopSize);
                int sz2 = st.query(0, (start + length) % loopSize);
                remaining = sz1 + sz2;
            }

            cout << base << ' ' << loop << ' ' << remaining << '\n';

            int res = base + loop + remaining;
            cout << res << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            --x;

            pii on = at[x];
            SegTree st = sts[on.first];

            st.update(on.second, y);
            b[x] = y;
        }
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
    