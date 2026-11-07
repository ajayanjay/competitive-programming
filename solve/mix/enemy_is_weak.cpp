#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define ull unsigned ll
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

struct Fenwick {
    ll n;
    vector<ll> bit;

    Fenwick(vector<ll>& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);
        build(arr);
    }

    Fenwick(ll n) : n(n), bit(n + 1, 0) {}

    void build(vector<ll>& arr) {
        for (ll i = 1; i <= n; ++i) {
            bit[i] += arr[i - 1];
            ll j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    void update(ll i, long long delta) {
        for (; i <= n; i += i & -i){
            bit[i] += delta;
        }
    }

    ll query(ll i) {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }

    ll query(ll l, ll r) {
        return query(r) - query(l - 1);
    }
};

#define MX 1000000001

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    vi b, c;
    for (auto & e : a) {
        cin >> e;
        b.pb(e);
        c.pb(MX - e);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    sort(all(c));
    c.erase(unique(all(c)), c.end());

    // left greater
    // i < j
    // a_i > a_j -> (n - a_i) < (n - a_j)

    // right smaller
    // j < k
    // a_j > a_k

    Fenwick l(n + 1), r(n + 1);
    ll left = 0, right = 0;

    ull res = 0;

    vi lg(n), rg(n);
    for (ll i = 0; i < n; ++i) {
        ll e = MX - a[i];

        ll idx = lower_bound(all(c), e) - c.begin() + 1; // 1 indexed

        l.update(idx, 1);

        ll cl = l.query(idx) - 1;

        lg[i] = cl;
    }

    for (ll i = n - 1; i >= 0; --i) {
        ll e = a[i];
        ll idx = lower_bound(all(b), e) - b.begin() + 1; // 1 indexed

        r.update(idx, 1);
        ll cr = r.query(idx) - 1;
        rg[i] = cr;

    }

    for (ll i = 0; i < n; ++i) {
        res += lg[i] * rg[i];
    }

    cout << res;
}

int main() {
    // fast_io;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}