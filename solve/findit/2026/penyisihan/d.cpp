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
#define MOD 1000000007
#define MAXN 500000

ll factorial(ll n) {
    ll sm = 1;
    for (int i = 1; i <= n; ++i) {
        sm *= i;
    }
    return sm;
}

pair<int, ll> dfs(vector<vi> &g, int u, vector<bool> &vis) {
    if (vis[u] == true) return {0, 1};

    ll sm = factorial(g[u].size());
    if (sm == 0) sm = 1;

    ll cnt = g[u].size();
    for (auto v: g[u]) {
        auto [count, val] = dfs(g, v, vis);
        cnt += count;
        sm *= val;
        vis[v] = true;
    }
    return {cnt, sm};
}

ll findHead(vi g, int curr, vector<bool> &vis) {
    vis[curr] = true;
    int next = g[curr];
    if (next == -1) return curr;
    else {
        return findHead(g, next, vis);
    }

}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> gdfs(n);
    vi g(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        gdfs[v].push_back(u);
        g[u] = v;
    }

    // pair <sectorCount, val>
    vector<pair<int, ll>> forests;
    vector<bool> vis(n, false);
    vector<bool> visdfs(n, false);
    vector<bool> isHead(n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;

        int head = findHead(g, i, vis);
        if (isHead[head]) continue;
        isHead[head] = true;

        auto[cnt, val] = dfs(gdfs, head, visdfs);
        cnt += 1;
        forests.push_back({cnt, val});

        cout << "head of " << i << " is: " << head << '\n';
        cout << "cnt: " << cnt << ", val: " << val << '\n';
    }

    cout << "forest count: " << forests.size() << '\n';

    // the magic thing who the fuck knows
    // forest i can be inserted at forest j at any time in forest j steps.
    // this means that if we iterate i from 1 to N and "insert" i to 1, we might be able to get the result.
    // but how can we insert.

    // if 1 we can do (val * (count + 1))
    // but if 2 we have to use combination bs

    auto [firstCount, firstVal] = forests[0];
    cout << "firstCount: " << firstCount << ", firstVal: " << firstVal << '\n';
    for (int i = 1; i < forests.size(); ++i) {

        auto [currCount, currVal] = forests[i];
        firstVal *= pow(firstCount + 1, currCount);
        firstCount = firstCount + currCount;
    }

    cout << firstVal;
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
    