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
    double x; int l, r;
    cin >> x >> l >> r;

    if (x < l || x > r) {
        cout << -1;
        return;
    }

    if (x == l) {
        cout << 1 << '\n' << l;
        return;
    }

    if (x == r) {
        cout << 1 << '\n' << r;
        return;
    }

    int mul = 1;
    ll total;

    auto round5 = [&] (double val) {
        return val * 100000.0 / 100000.0;
    };

    while (1) {
        double dx = x * mul;

        int f = (int) dx, c = ceil(dx);

        double df = round5((double) f / mul);
        double dc = round5((double) c / mul);

        if (df == x) {
            total = f;
            break;
            
        } else if (dc == x) {
            total = c;
            break;
        }
        ++mul;
    }

    // construct array whose size is mul and the total is total, with the element ranging from l to r

    // the idea is that we take the floor(avg) and the remaining should be + 1

    ll e = total / mul;
    ll res = total % mul;

    cout << mul << '\n';
    for (int i = 0; i < mul; ++i) {
        if (i < res) {
            cout << e + 1 << ' ';
        } else {
            cout << e << ' ';
        }
    }
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
    