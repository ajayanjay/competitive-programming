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

int operate(int a, int b, char op) {
    return op == '+' ? a + b : a * b;
}

int mx4(int a, int b, int c, int d) {
    int mx = a;

    mx = max(mx, b);
    mx = max(mx, c);
    mx = max(mx, d);
    return mx;
}

int mn4(int a, int b, int c, int d) {
    int mn = a;

    mn = min(mn, b);
    mn = min(mn, c);
    mn = min(mn, d);

    return mn;
}

void solve() {
    int n, p;
    cin >> n >> p;

    int mn = p, mx = p;
    for (int i = 0; i < n; ++i) {
        char o1, o2;
        int e1, e2;

        cin >> o1 >> e1 >> o2 >> e2;

        int mn1 = operate(mn, e1, o1);
        int mn2 = operate(mn, e2, o2);
        int mx1 = operate(mx, e1, o1);
        int mx2 = operate(mx, e2, o2);

        mn = mn4(mn1, mn2, mx1, mx2);
        mx = mx4(mn1, mn2, mx1, mx2);

        // cout << mn1 << ' ' << mn2 << ' ' << mx1 << ' ' << mx2 << ' ' << mn << ' ' << mx << '\n';
    }

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
    