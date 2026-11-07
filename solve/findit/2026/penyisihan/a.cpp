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


ll dijkstra2(const vector<vector<pii>>& g, int src, int dest) {
    int n = g.size();
    vector<ll> dist(n, LLONG_MAX);
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
    int n;
    cin >> n;

    vector<vector<pii>> g(n);

    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;

        for (int j = 0; j < n; ++j) {
            int cost = e * abs(i - j);
            g[i].push_back({j, cost});
        }
    }

    cout << dijkstra2(g, 0, n - 1);
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
    