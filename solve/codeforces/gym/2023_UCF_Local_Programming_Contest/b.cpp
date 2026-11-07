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

struct _t {
    int i, arrival, service, patience;

    int timeLeave;
};

void solve() {
    int n;
    cin >> n;

    vector<_t> a(n);
    for (auto&[i, ar, s, p, tl]: a) {
        cin >> i >> ar >> s >> p;

        tl = ar + p;
    }

    // ar will always be larger
    // ar_i < ar_j: i < j

    vi ans;
    _t first = a[0];
    int timeNow = first.arrival + first.service;
    ans.push_back(first.i);

    for (int i = 1; i < n; ++i) {
        _t curr = a[i];
        if (timeNow > curr.timeLeave) continue;
        else { // timeNow <= timeLeave
            timeNow = max(timeNow, curr.arrival);
            timeNow += curr.service;
            ans.pb(curr.i);
        }
    }

    for (auto e : ans) {
        cout << e << '\n';
    }


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
    