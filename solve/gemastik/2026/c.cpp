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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto&x : a) cin>>x;
    
    for (int i = 0 ; i < m; ++i) {
        cin >> b[i];
    }

    for (int i = m; i < n; ++i) {
        b[i] = 0;
    }

    sort(all(b));

    int ans = 0;
    for (int i =0 ; i < n; ++i) {
        ans += a[i] * b[i];
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
    