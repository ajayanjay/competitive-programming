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

void djikstra(vector<vector<pii>> &g, int start, int end) {
	int n = g.size();

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> vis(n, false);
	vll dist(n, LLONG_MAX);

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		vis[u] = true;
		if (d > dist[u]) continue;

		for (auto [v, w] : g[u]) {
			if (vis[v] && dist[u] + w < 0) {
				cout << "Pak Dengklek tidak mau pulang\n";
				return;
			} else if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	if (!vis[end]) {
		cout << "Tidak ada jalan\n";
		return;
	}

	cout << dist[end] << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);

    for (int i = 0; i < m; ++i ) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    }

    djikstra(g, 0, n - 1);

}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
