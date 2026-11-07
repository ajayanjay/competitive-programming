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

// BFS for single connected component
void bfs(vector<vector<int>>& adj, vi &a, int src) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res(V);

    for (int i = 0; i < V; ++i) {
    	res[i] = a[i];
    }
    
    queue<int> q;
    
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;

                res[x] = min(res[x], res[curr]);

                q.push(x);
            }
        }
    }

    for (auto e : res)
    	cout << e << ' ';
    
}

void solve() {
    int n, x;
    cin >> n >> x;

    --x;

    vi a(n);
    for (auto &e : a) 
    	cin >> e;

    vector<vi> g(n);

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	cin >> u >> v;

    	--u; --v;

    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    bfs(g, a, x);
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
    