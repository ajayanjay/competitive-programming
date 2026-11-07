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

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(vector<int>& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);
        build(arr);
    }

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void build(vector<int>& arr) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += arr[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    long long query(int i) {
        long long res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }

    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

#define MX 1000000

void solve() {
    int n;
    cin >> n;

    vi a(n), b;
    for (auto &e : a) {
    	cin >> e;
        b.pb(e);
    }

    // create index
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    vi forwCnt(n, 0), pref(n);
    for (int i = 0; i < n; ++i) {
        int e = a[i];

        int idx = lower_bound(all(b), e) - b.begin();
        pref[i] = (++forwCnt[idx]);
    }

    vi backCnt(n, 0), suff(n);
    for (int i = n - 1; i >= 0; --i) {
        int e = a[i];

        int idx = lower_bound(all(b), e) - b.begin();
        suff[i] = (++backCnt[idx]);
    }

    // pref[i] = f(1, i, ai), suff[j] = f(j, N, aj)
    // count all i < j, pref[i] > suff[j]

    Fenwick f(MX);
    for (int i = 1 ; i < n ; ++i) {
        int e = suff[i];
        f.update(e, 1);
    }

    ll res = 0;
    for (int i = 0; i < n - 1; ++i) {
        int e = pref[i];
        int c = suff[i + 1];

        res += f.query(e - 1);
        f.update(c, -1);
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
    