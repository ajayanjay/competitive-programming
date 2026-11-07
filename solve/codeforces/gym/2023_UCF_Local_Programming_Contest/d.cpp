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
#define ld double

const double PI = 3.141592653589793;

int sign(ld x) {
    return x < 0 ? -1 : 1;
}

void solve() {
    int y, x, r;
    cin >> y >> x >> r;
    x = abs(x);

    ld x1 = x;
    ld y1 = 0;
    ld x2 = 0;
    ld y2 = y;

    ld dx = x2 - x1;
    ld dy = y2 - y1;
    ld dr = sqrt(dx * dx + dy * dy);
    ld D = x1 * y2 - x2 * y1;

    ld det = r * r * dr * dr - D * D;
    ld sqrt_det = sqrt(det);

    if (det < 0) {
        cout << -1;
        return;
    }

    ld res_x1 = (D * dy - sign(dy) * dx * sqrt_det) / (dr * dr);
    ld res_y1 = (-D * dx - abs(dy) * sqrt_det) / (dr * dr);

    ld ans = atan(res_y1 / res_x1);
    ans = ans * (180 / PI);
    cout << fixed << setprecision(6) << ans;

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
    