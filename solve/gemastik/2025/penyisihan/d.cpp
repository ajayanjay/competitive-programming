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

void solve() {
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pii>> g(vertices + 1);

	for (int i = 0; i < edges; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	auto [d1, path1] = dijkstra(g, 1, 2);
	ll len = path1.size();

	for (int i = 0; i < len - 1; ++i) {
		int u = path1[i], v = path1[i + 1];
		for (auto &p : g[u]) 
			if (p.first == v) {
				if (p.second % 2 != 0) ++p.second;
				p.second /= 2;

				break;
			}
		for (auto &p : g[v]) 
			if (p.first == u) {
				if (p.second % 2 != 0) ++p.second;
				p.second /= 2;

				break;
			}
    }

	ll d2 = dijkstra2(g, 2, 3);
	cout << d1 + d2 << "\n";
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
