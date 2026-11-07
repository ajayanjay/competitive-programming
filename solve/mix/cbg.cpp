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

void printBFS(int n, vector<pii> &edges) {
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

    func(adj_mat);
}

void solve() {
    int n, m;
    cin >> n >> m;

    // yeah this is crazy
    vector<vector<int>> level(1);
    vector<int> bfs(n);
    vector<int> at_level(n + 1);

    int lvl_cnt = 0;
    int before = INT_MAX;

    level[0].push_back(1);
    bfs[0] = 1;
    int _;
    cin >> _;

    for (int i = 0; i < n - 1; ++i) {
        int a;
    	cin >> a;
        bfs[i + 1] = a;
        
        if (a < before) {
            level.push_back({});
            ++lvl_cnt;
        }

        at_level[a] = lvl_cnt;

        level[lvl_cnt].push_back(a);
        before = a;
    }

    if (n - 1 > m || (m > (n * (n - 1) / 2))) {
    	cout << -1 << ' ' << -1;
    	return;
    }

    if (n - 1 == m) {
    	before = 1;
        for (auto lvl : level) {
            for (auto e : lvl) {
                if (e == 1) continue;
                cout << before << ' ' <<  e << '\n';
                before = e;
            }
        }
    	return;
    }

    vector<pii> edges;

    before = 1;
    for (int i = 1; i < level.size(); ++i) {
        for (int j = 0; j < level[i].size(); ++j) {
            edges.push_back({before, level[i][j]});
        }
        before = level[i][0];
    }
    
    m -= (n - 1);

    // first iteration, the "what the hell is this" operation
    // the idea is that we connect every combination in each level.

    for (int i = 1; m > 0 && i < level.size(); ++i) {
        for (int j = 0; m > 0 && j < level[i].size() - 1; ++j) {
            for (int k = j + 1; m > 0 && k < level[i].size(); ++k) {
                edges.push_back({level[i][j], level[i][k]});
                --m;
            }
        }
    }

    if (m == 0) {
        for (auto p : edges) 
            cout << p.first << ' ' << p.second << '\n';
        return;
    }

    // second iteration, the "yeah this aint gonna work" operation
    // the idea is that bfs[i] can connect with level[i + 1]
    // bfs[0] can connect with level[1]
    // bfs[1] can connect with level[1..2]
    // bfs[2] can connect with level[1..3]
    // suppose bfs[i] is the first entry of level[j], we update the range.

    for (int i = 1; m > 0 && i < n; ++i) {
        int u = bfs[i];
        int lvl = at_level[u];

        for (int j = lvl + 1; m > 0 && j <= i + 1 && j < level.size(); ++j) {

            if (u == level[lvl][0] && j == lvl + 1) continue;

            for (int k = 0; m > 0 && k < level[j].size(); ++k) {
                int v = level[j][k];

                edges.push_back({u, v});
                --m;
            }
        }
    }
 
    // printBFS(n, edges);
 
    if (m == 0) {
        for (auto p : edges) 
            cout << p.first << ' ' << p.second << '\n';
        return;
    } else {
        cout << -1 << ' ' << -1;
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
    