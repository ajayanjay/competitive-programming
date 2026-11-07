#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

struct SegTree {
    ll n;
    vector<ll> tree;
    vector<ll> lazy;
    
    SegTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    ll combine(ll a, ll b) {
    	if (a == LLONG_MIN) return b;
    	if (b == LLONG_MIN) return a;	

        return min(a, b);
    }

    ll make_node(ll item) {
        return item;
    }
    
    void build(vector<ll>& arr, ll node, ll start, ll end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            ll mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void push(ll v) {
	    tree[v*2] += lazy[v];
	    lazy[v*2] += lazy[v];
	    tree[v*2+1] += lazy[v];
	    lazy[v*2+1] += lazy[v];
	    lazy[v] = 0;
	}

    void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
	    if (l > r) 
	        return;
	    if (l == tl && tr == r) {
	        tree[v] += addend;
	        lazy[v] += addend;
	    } else {
	        push(v);
	        ll tm = (tl + tr) / 2;
	        update(v*2, tl, tm, l, min(r, tm), addend);
	        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
	        tree[v] = combine(tree[v*2], tree[v*2+1]);
	    }
	}

    // single poll update.
    void update(ll node, ll start, ll end, ll position, ll newValue) {
        if (start == end) tree[node] = make_node(newValue);
        else {
            ll mid = (start + end) / 2;
            if (position <= mid)
                update(node * 2, start, mid, position, newValue);
            else
                update(node * 2 + 1, mid + 1, end, position, newValue);

            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }
    
    ll query(ll v, ll tl, ll tr, ll l, ll r) {
	    if (l > r)
	        return LLONG_MIN;
	    if (l == tl && tr == r)
	        return tree[v];

	    push(v);
	    ll tm = (tl + tr) / 2;

	    return combine(
	    	query(v*2, tl, tm, l, min(r, tm)), 
	    	query(v*2+1, tm+1, tr, max(l, tm+1), r)
	    );
	}
    
    ll query(ll l, ll r) { return query(1, 0, n - 1, l, r); }
    ll query() { return query(0, n - 1); }

    void update(ll l, ll r, ll v) { update(1, 0, n - 1, l, r, v); }
};

void solve() {
	ll n;
	cin >> n;

	vi a(n);
	for (auto &e: a) {
		cin >> e;
	}

	SegTree st(a);

	ll q;
	cin >> q;
	cin.ignore();
	while (q--) {
		string s;
		getline(cin, s);
		stringstream ss(s);

		ll l, r, v;
		ss >> l >> r;

		bool circle = l > r;

		if (ss >> v) { // v exist, increment operation

			if (circle) {
				st.update(l, n - 1, v);
				st.update(0, r, v);
			} else {
				st.update(l, r, v);
			}

			// st.prll();

		} else { // rmq operation
			if (circle) {
				ll a = st.query(l, n - 1);
				ll b = st.query(0, r);

				// cout << a << ' ' << b << ' ';
				cout << min(a,b) << '\n';
			} else {
				cout << st.query(l, r) << '\n';
			}
		}
	}
    
}

int main() {
    fast_io;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    