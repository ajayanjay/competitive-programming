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

int djikstra(vector<vector<pii>> &g, int start, int end) {
	int n = g.size();

	vll dist(n, LLONG_MAX);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (d > dist[u]) continue;

		for (auto [v, w] : g[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist[end];
}

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    --p, --q;

    vector<vector<pii>> g(n);

    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	--u, --v;

    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }

    cout << djikstra(g, p, q);
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
    