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
    int n;
    cin >> n;
    vi a(n);
    for (auto & e : a) 
        cin >> e;

    int mx = INT_MIN;
    int prev = -1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i += 2) {

        if (prev == -1) {
            prev = a[i];
            l = 0;
        } else {

            int diff = abs(prev - a[i]);
            if (diff == 0 || diff == 2) {
                r = i;
            } else {

                // cout << l << ' ' << r << '\n';

                int cnt = r - l + 1;
                if (l > 0) ++cnt;
                if (r < n - 1) ++cnt;
                mx = max(mx, cnt);
                
                l = i;
                r = i;
            }

            prev = a[i];
        }
    }

    // cout << l << ' ' << r << '\n';

    int cnt = r - l + 1;
    if (l > 0) ++cnt;
    if (r < n - 1) ++cnt;
    mx = max(mx, cnt);


    cout << mx;



    
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
    