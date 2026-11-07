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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pii> t(n);
    for (auto &[w, v] : t) {
        cin >> w >> v;
    }

    vi s(m);
    for (auto & e : s) {
        cin >> e;
    }

    sort(all(t));
    sort(all(s));

    // both sorted ascending

    /*
        for each weight w on cart 
            find largest value for weigth <= w, modified lowerbound
            if found adds to ans

        cout ans
    */

    multiset<int> ms;
    int prevIdx = 0;
    int ans = 0;
    for (auto w : s) {
        
        int i;
        for (i = prevIdx; i < n && w >= t[i].first; ++i) {
            ms.insert(t[i].second);
        }
        prevIdx = i;

        if (!ms.empty()) {
            auto lastIdx = prev(ms.end());
            ans += *lastIdx;
            ms.erase(prev(ms.end()));
        }
    }

    cout << ans;
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
    