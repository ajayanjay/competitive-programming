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

ull dfs(vector<set<char>> &adj, vector<vector<char>> &m, char u, int depth) {

    if (depth == 1) {
        ull res = 0;

        for (auto c : adj[u - 'a']) {
            if (m[u - 'a'][c - 'a'] == 'a') ++res;
        }

        return res;
    }


    ull res = 0;
    for (auto c : adj[u - 'a']) {
        res += dfs(adj, m, m[u - 'a'][c - 'a'], depth - 1);
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;

    int operations = n - 1;

    vector<set<char>> adj(6);

    vector<vector<char>> m(6, vector<char>(6, 0));

    for (int i = 0 ; i < q; ++ i ) {
        string seq;
        cin >> seq;

        char c;
        cin >> c;

        m[seq[0] - 'a'][seq[1] - 'a'] = c;

        c = seq[1];
        char a = seq[0];

        adj[a - 'a'].insert(c);
    }

    
    ull res = 0;

    for (int i = 0 ;i < 6; ++i) {
        res += dfs(adj,m, i + 'a', operations);
    }

    cout << res;


    // init: bbbbba
    // bbbba
    // bbba
    // bba
    // ba
    // a
    // ----
    // 5 operations..???

    // init: bbbbbb
    // bbbba
    // bbba
    // bba
    // ba
    // a
    // ----
    // also 5 operations...???

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
    