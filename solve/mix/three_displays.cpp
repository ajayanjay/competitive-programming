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
    int n;
    cin >> n;

    vi s(n);
    for (auto &e: s) cin >> e;

    vi c(n);
    for (auto &e: c) {
    	cin >> e;
    }

    ll pref, suff;
    ll res = LLONG_MAX;
    for (int i = 0; i < n; ++i ) {
        int mn = INT_MAX;
        bool f1 = false;

        // j < i, sj < si
        for (int j = 0; j < i; ++j) {
            if (s[j] >= s[i]) continue;
            else {
                mn = min(mn, c[j]);
                f1 = true;
            }
        }

        pref = mn;
        mn = INT_MAX;
        bool f2 = false;

        // i < j, si < sj
        for (int j = i + 1; j < n; ++j) {
            if (s[i] >= s[j]) continue;
            else {
                mn = min(mn, c[j]);
                f2 = true;
            }
        }
        suff = mn;

        if (f1 && f2) {
            res = min(res, pref + suff + c[i]);
        }
    }

    if (res == LLONG_MAX) cout << -1;
    else cout << res;
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
