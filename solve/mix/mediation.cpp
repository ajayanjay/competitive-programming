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

void solve() {

	int n, s1, s2;
	cin >> n >> s1 >> s2;

	vector<vector<pii>> adj(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<pii> d(n + 1);

	function<void(int, int, int, int)> dfs = [&](int u, int parent, bool f, int weight) {
		f ? d[u].first = weight : d[u].second = weight;

		for (auto [v, w] : adj[u]) {
			if (v == parent) continue;
			dfs(v, u, f, weight + w);
		}
	};
    
    dfs(s1, -1, true, 0);
    dfs(s2, -1, false, 0);

    sort(all(d));

    // since d is sorted on d1, when we got to d2 we can find where d2 could be placed on d1 using lower_bound, thus getting the index
    auto idxOf = [&](int x) {
    	return lower_bound(all(d), x) - d.begin();
    };

    Fenwick fw(n + 1);

    /*
    for each u
    	D1u <= D1v && D2u <= D2v -> max(D1u, D2u) count how many v satisfy this -> 
		D1u > D1v && D2u > D2v -> max(D1v, D2v) no need to do anything
		D1u <= D1v && D2u > D2v -> max(D1u, D2v) query D1u <= D2v -> query(D2v)
		D1u > D1v && D2u <= D2v -> max(D1v, D2u) query D1v <= D2u -> query(D2u)
    */

    // j > i && max(min(D1i, D1j), min(D2i, D2j))
    auto M = [&](int u, int v) {
    	return max(min(d[u].first, d[v].first), min(d[u].second, d[v].second));
    };

    ll res = 0;
    for (int i = 1; i < n; ++i)
    	for (int j = i + 1; j <= n; ++j)
    		res += M(i, j);

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
    