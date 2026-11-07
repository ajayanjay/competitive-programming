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
#define ull unsigned ll

struct attr {
	int v, cost, time;
};

ll dijkstra(const vector<vector<attr>>& g, int src, int dest) {
	int n = g.size();
	vector<ll> dist(n, LLONG_MAX);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dist[u]) continue;
		if (u == dest) return d;

		for (auto [v, c, t] : g[u]) {
			ll curr = d;

			int div = 0;
			if (t < 0) {
				t = -t;
				div = 1;
			}

			if ((curr / t) % 2 != div) {
				curr = ((curr / t) + 1) * t;
			}

			if (dist[v] > curr + c) {
				dist[v] = curr + c;
				pq.push({dist[v], v});
			}
		}
	}
	return -1;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<attr>> g(n + 1);

    for (int i = 0; i < k; ++i) {
    	int u, v, c, t;
    	cin >> u >> v >> c >> t;

    	g[u].push_back({v, c, t});
    	g[v].push_back({u, c, -t});
    }

    int x, y;
    cin >> x >> y;

    cout << dijkstra(g, x, y);
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
    