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
	vector<int> f;

	Fenwick(int n): n(n), f(n + 1, 0) {}

	void update(int i, int v) {
		for (; i <= n; i += i & -i)
			f[i] += v;
		print();
	}

	void print() {
		for (auto e : f) {
			cout << e << ' ';
		}
		cout << '\n';
	}

	ll query(int i) {
		ll s = 0;
		for (;i > 0; i -= i & -i) 
			s += f[i];
		return s;
	}

	ll query(int l, int r) {
		return l > r ? 0 : query(r) - query(l - 1);
	}
};

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n + 1);
    for (int i = 1; i <= n; ++i) 
    	cin >> a[i];
    
    vi last(m + 1, 0);
    Fenwick fw(n);

    ll adjSum = 0;
    for (int i  = 1; i <= n; ++i) {
    	int x = a[i];
    	int l = last[x];

    	if (l > 0) fw.update(l, -1);

    	adjSum += fw.query(l + 1, i - 1);
    	fw.update(i, 1);
    	last[x] = i;
    }

    ll c = 0;

    // size of set(A)
    for (int x = 1; x <= m; ++x)
    	if (last[x] > 0) ++c;

    // the total of the element not existed in A.
    ll missing = c * (m - c);

    // sum of existing pairs.
    ll existing = c * (c - 1) / 2;

    ll ans = adjSum + missing + existing;

    cout << ans;
    
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