#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int mn = -1;
    bool same = true;
    for (int i = 0; i < n; ++i) {
        int curr = t[i] - '0';
        int cand = s[i] - '0';

        if (same) {
            if (cand < curr) { // cand is lower, number automatically lower.
                mn = 0;
                break;
            }

            if (cand != curr) { // number changed and is higher, swap needed.
                same = false;
            }
        }

        for (int j = i + 1; j < n; ++j) {
            cand = s[j] - '0';

            if (i == 0 && cand == 0) continue;

            if (curr < cand) {
                if (mn == -1) mn = INT_MAX;
                mn = min(mn, j - i + 1);
                break;
            }
        }
    }

    cout << mn;
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