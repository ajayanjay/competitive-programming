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
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto &e: a) {
        cin >> e;
    }

    sort(all(a)); // a now acts as a lib

    vi suffSum(a); // quick fetch
    for (int i = n - 2; i >= 0; --i) {
        suffSum[i] += suffSum[i + 1];
    }

    // for (auto e : suffSum) {
    //     cout <<e << ' ';
    // } cout << '\n';

    vi ans(200000, -1);
    while (q--) {
        int x;
        cin >> x;

        if (ans[x - 1] != -1) {
            cout << ans[x - 1] << '\n';
            continue;
        }

        // start right most.
        int prev = n;
        int res = 0;
        for (int i = n - x; i >= 0; i -= x) {
            if (prev == n)
                res += suffSum[i] - (a[i] / 2); 
            else
                res += (suffSum[i] - suffSum[prev]) - (a[i] / 2);

            prev = i;
        }

        if (prev > 0 && prev != n) {
            res += (suffSum[0] - suffSum[prev]);
        } else if (prev == n) {
            res += suffSum[0];
        }

        ans[x - 1] = res;
        cout << res << '\n';
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
    