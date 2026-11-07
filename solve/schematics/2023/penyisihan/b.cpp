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
#define ld long double

void solve() {
 	int n;
    cin >> n;

 	vi a(n);
 	for (auto &e : a){
 		cin >> e;
 	}   

 	ld tol = 0.000001;

    ld prevZero = 0;
    ld res = a[n - 1];
    int i = min(n - 2, 1LL * 0);
    while (true) {
        res = a[i] + 1 / res;

        // cout << i << ' ' << res << '\n';

        if (i == 0 && abs(res - prevZero) < tol){
            break;
        }

        --i;

        if (i < 0) {
            i = n - 1;
            prevZero = res;
        }
    }

    cout << fixed << setprecision(6) << res << '\n';
}

signed main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    