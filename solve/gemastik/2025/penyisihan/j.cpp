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
    	if (r < l) return 0;
        return query(r) - query(l - 1);
    }
};

const ll INF = 1e18;

pair<ll, vector<int>> dijkstra(const vector<vector<pii>>& g, int src, int dest) {
	int n = g.size();
	vector<ll> dist(n, INF);
	vector<int> parent(n, -1);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dist[u]) continue;
		if (u == dest) break;

        for (auto [v, w] : g[u]) {
			if (dist[v] > d + w) {
				dist[v] = d + w;
				parent[v] = u;
				pq.push({dist[v], v});
			}
		}
	}

	if (dist[dest] == INF) return {-1, {}};

	vector<int> path;
	for (int v = dest; v != -1; v = parent[v])
		path.push_back(v);
	
	return {dist[dest], path};
}

ll dijkstra2(const vector<vector<pii>>& g, int src, int dest) {
	int n = g.size();
	vector<ll> dist(n, INF);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dist[u]) continue;
		if (u == dest) return d;

		for (auto [v, w] : g[u]) {
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}
	return -1;
}

int dist[2][200001];

void preorder(vector<vector<pii>> &g, int strict, int parent, int curr_node, int curr_w) {
	dist[strict][curr_node] = curr_w; 

	for (auto e: g[curr_node]) {
		if (e.first != parent) {
			preorder(g, strict, curr_node, e.first, curr_w + e.second);
		}
	}
}

int m(int u, int v) {
	return max(min(dist[0][u], dist[0][v]), min(dist[1][u], dist[1][v]));
}

void solve() {
	int vertices, s1, s2;
	cin >> vertices >> s1 >> s2;

	vector<vector<pii>> g(vertices + 1);

	for (int i = 0; i < vertices - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dist[0][s1] = 0;
	dist[1][s2] = 0;

	preorder(g, 0, -1, s1, 0);
	preorder(g, 1, -1, s2, 0);

	vector<pair<ll, ll>> nodes;
	nodes.reserve(vertices);
	for (int i = 1; i <= vertices; ++i)
		nodes.push_back({dist[0][i], dist[1][i]});

	sort(all(nodes));

	vll vals;
	vals.reserve(vertices);
	for (auto & p : nodes)
		vals.push_back(p.second);

	sort(all(vals));
	vals.erase(unique(all(vals)), vals.end());
	int M = vals.size();

	auto idxOf = [&](ll x) {
		return int (lower_bound(all(vals), x) - vals.begin()) + 1;
	};

	Fenwick fwCnt(M), fwSum(M);
	for (auto & p: nodes) {
		int idx = idxOf(p.second);
		fwCnt.update(idx, 1);
		fwSum.update(idx, p.second);
	}

	ll ans = 0;
	for (int i = 0; i < vertices; ++i) {
		ll a = nodes[i].first;
		ll b = nodes[i].second;

		int idxB = idxOf(b);
		fwCnt.update(idxB, -1);
		fwSum.update(idxB, -b);

		ll totalCnt =  fwCnt.query(M);
		if (totalCnt == 0) continue;

		if (b < a) {
			ans += a * totalCnt;
		} else {
			int idxA = idxOf(a);

			ll cntLessA = 0;
			if (idxA > 1) cntLessA = fwCnt.query(idxA - 1);

			ll cntGeB = 0;
			// same thing as fwCnt.query(idxB - 1, M);
			if (idxB <= M)  cntGeB = totalCnt - fwCnt.query(idxB - 1);

			// same thing as fwCnt.query(idxA - 1, idxB - 1);
			ll cntBetween = totalCnt - cntLessA - cntGeB;

			ll sumBetween = 0;
			if (idxA <= idxB - 1) sumBetween = fwSum.query(idxA, idxB - 1);
			ll sumGeB = b * cntGeB;
			ll sumLessA = a * cntLessA;

			ans += sumLessA + sumBetween + sumGeB;
		}
	}

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
