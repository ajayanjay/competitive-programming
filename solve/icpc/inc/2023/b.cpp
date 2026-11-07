#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

short dp[101][101][101] = {0};

int dfs(vi& p, int i, int m, int k) {
    int n = p.size();
    if (i >= n) return n;
    if (m == 0 && k == 0) return i;
    if (dp[i][m][k] != 0) return dp[i][m][k];

    int milkNeeded = p[i];
    int mx = i;
    if (milkNeeded <= m) {
        mx = max(mx, dfs(p, i + 1, m - milkNeeded, k));
    }

    if (k > 0) {
        mx = max(mx, dfs(p, i + 1, m, k - 1));
    }

    dp[i][m][k] = mx;

    return mx;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vi p(n);
    for (auto &e : p) {
        cin >> e;
    }

    // m ml milk, k biscuits
    // day i, need drink exactly Pi, or eat biscuit

    cout << dfs(p, 0, m, k);

}

signed main() {
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
    