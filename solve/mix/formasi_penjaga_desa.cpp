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

int minDFS(vector<vector<int>>& g, vector<bool> &vis, vector<int>& mn, int u) {
	if (vis[u]) return mn[u];
	vis[u] = true;

	int currMin = INT_MAX;
	for (auto v : g[u]) {
		if (!vis[v])
			currMin = min(currMin, minDFS(g, vis, mn, v));
	}

	mn[u] = currMin;
	return currMin;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vi b(n);
    for (auto& e: b)
    	cin >> e;

    vi w(k);
    for (auto& e:w)
    	cin >> e;

    vector<vector<int>> gOut(n, vector<int>()); // out degree
    vector<vector<int>> gIn(n, vector<int>()); // in degree

    vector<int> mn(b);

    for (int i = 0; i < m; ++i) {
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	gOut[u].push_back(v);
    	gIn[v].push_back(u);
    }

    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
    	minDFS(gOut, vis, mn, i);
    }




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
