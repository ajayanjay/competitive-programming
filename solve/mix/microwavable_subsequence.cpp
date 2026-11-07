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

struct FenTree {
    int n;
    vector<ll> bit;

    FenTree(vi& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);
        build(arr);
    }  

    FenTree(int n) : n(n), bit(n + 1, 0) {}

    void build(vi& arr) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += arr[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, ll delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    ll query(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }

    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void print() {
        for (auto e : bit)
            cout << e << ' ';
        cout << '\n';
    }
};

int f(vector<int> &a, int x, int y) {
	int cnt = 0;
	int bef = 0;
	for (auto e : a) {
		if ((e != x && e != y) || (bef == e)) continue;

		bef = e;
		++cnt;
	}
	return cnt;
}

void solve() {
	int n, m;
	cin >> n >> m;

	FenTree fw(n);
    vi last(m + 1, -1);

    ll res = 0;

    fw.print();
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;

        int l = last[e];

        res += fw.query(l + 1, i);

        if (l > 0)
            fw.update(l, -1);

        fw.update(i + 1, 1);

        last[e] = i + 1;
        fw.print();
    }

    int c = 0;
    for (int i = 0; i < m + 1; ++i)
        if (last[i] != - 1) ++c;

    res += (ll) c * (m - c);
    res += (ll) c * (c - 1) / 2;

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
    