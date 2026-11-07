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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> bfs(n);

    for (auto & a : bfs)
    	cin >> a;

    vector<pii> edges;

    if (n - 1 > m) {
    	cout << -1 << ' ' << -1;
    	return;
    }

    if (n - 1 == m) {
    	for (int i = 0 ; i < n - 1; ++ i )
    		cout << bfs[i] << ' ' << bfs[i + 1] << '\n';
    	return;
    }

    for (int i =0 ; i < n - 1; ++i)
    	edges.push_back({bfs[i], bfs[i + 1]});

    m -= (n - 1);

    vector<bool> vis(n, false);

    for (int i = 0; i < n - 2; ++i) {
    	int u = bfs[i];
    	
    	int j = i;
    	while (m > 0 && (j + 2) < n && bfs[j + 1] <= bfs[j + 2]) {
    		edges.push_back({u, bfs[j + 2]});
    		--m;
    		++j;
    	}

    	if (m == 0) break;

        if ((j + 2) < n && !vis[bfs[j + 2] - 1]) {
            u = bfs[j + 2];
            vis[u - 1] = true;
            int k = i + 1;
            while (m > 0 && k < j + 1) {
                edges.push_back({u, bfs[k]});
                ++k;
                --m;
            }
        }

        if (m == 0) break;
    }

    if (m != 0){
    	cout << -1 << ' ' << -1;
        return;
    }
    else
    	for (auto p : edges)
    		cout << p.first << ' ' << p.second << '\n';

        vector<vector<int>> adj_mat(n, vector<int>(n, 0));
    for (auto p : edges) {
        adj_mat[--p.first][--p.second] = 1;
        adj_mat[p.second][p.first] = 1;
    }

    auto func = [](vector<vector<int>> & adj_mat) {
        set<int> vis;
        deque<int> q;

        vis.insert(0);
        q.push_back(0);

        while (!q.empty()) {
            int u = q.front();
            cout << u + 1 << ' ';
            q.pop_front();

            for (int v = 0; v < adj_mat.size(); ++v) {
                if (adj_mat[u][v] == 1 && vis.find(v) == vis.end()) {
                    q.push_back(v);
                    vis.insert(v);
                }
            }
        }
        cout << '\n';
    };

    for (auto a : bfs)
        cout << a << ' ';
    cout << '\n';   
    func(adj_mat);
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
    