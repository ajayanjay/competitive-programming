#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

int sign(char c) {
    switch (c) {
    case 'A': case 'B' : case 'C' : return 0;
    case 'D': case 'E' : case 'F' : return 1;
    }
    return -1;
}

int walk(char c) {
    switch (c) {
    case 'A': return 2;
    case 'B': return 1;
    case 'C': return 0;
    case 'D': return 0;
    case 'E': return 1;
    case 'F': return 2;
    }

    return -1;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    // C B A

    vector<vector<bool>> mp(n, vector<bool>(6, false));
    vi res;

    for (int i = 0; i < m; ++i) {
        int e;
        char c;
        cin >> e >> c;

        int s = sign(c);
        int w = walk(c);
        e--;

        int row = e;
        int col = s * 3; // 0 1 2 or 3 4 5

        int inc = 0;
        for (int j = 0; j < w; ++j) {
            if (mp[row][col + j]) {
                ++inc;
            }
        }

        mp[row][col + w] = true;

        res.push_back(inc);
    }

    sort(res.begin(), res.end());

    int ans = 0;
    for (int i = 0; i < res.size() - k; ++i) {
        ans += res[i];
    }

    cout << ans;

    /*
        1C
        1B
        1A
        x x x       +1 + 2 = 3
        A B C

        1C
        1B
        -> negative pending

        thinking of putting all pending on a single array
        [2, 2, 2, ....]

        and remove the first k elements
        and get the result
    
    */
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "YES\n";
        // else cout << "NO\n";
    }
}