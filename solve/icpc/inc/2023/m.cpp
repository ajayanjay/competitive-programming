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

int lwrbnd(int x, int k, int y) { 
    // find lowerbound x * i, on k, returns i

    // from 1 to y
    int l = 1;
    int r = y;

    int ans = -1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        int res = x * m;
        if (res <= k) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return ans;
}

void solve2() { // nah this ones dead
    int n, m, k;
    cin >> n >> m >> k;

    if (m > n) swap(n, m);
    // n always bigger.

    // initial chocolate bar width N height M (n x m)
    // want eat chocolate with area exactly K

    // oh shii got the question compleetely wrong
    /*
      we'll eat the biggest chunk everytime.

      that is the lowerbound of m * i on k or n * i on k

      do this until, well, k is satisfied.

      suppose we find m * i is beneficial
      hence
      k -= m * i

      new n = (n - i)
      m = m

      and repeat.
    */
    if (n * m == k) {
        cout << 0;
        return;
    }

    int ops = 0;
    while (k > 0) {
        int l = lwrbnd(n, k, m);
        int r = lwrbnd(m, k, n);

        int l1 = l * n;
        int r1 = r * m;

        cout << n << ' ' << m << ' ' <<  k << ' ';
        cout << l << ':' << l1 << ' ' << r << ":" << r1 << '\n';

        if (r1 == -1 || l1 >= r1) {
            k -= l1;
            m -= l;
        } else if (l1 == -1 || r1 > l1) {
            k -= r1;
            n -= r;
        } else {

        }

        ++ops;
    }
    cout << k << ' ';
    cout << ops;
    return;
}

int what(int n, int m, int k) {

    if (k == 0) {
        return 0;
    }

    int leftover = (n * m) - k;
    if (leftover == 0) {
        return 0;
    }

    if (k == n || k == m) {
        return 1;
    }

    if (leftover == n || leftover == m) {
        return 1;
    }

    if (leftover < n || leftover < m) {
        return 2;
    }

    // else.
    int l = lwrbnd(n, k, m);
    int r = lwrbnd(m, k, n);

    int mn = INT_MAX;
    if (l != -1) {
        int l1 = l * m;
        mn = min(mn, 1 + what(n, m - l, k - l1));
    } else if (r != -1) {
        int r1 = r * m;
        mn = min(mn, 1 + what(n - r, m, k - r1));
    }

    return mn;
}

void solve3() {
    int n, m, k;
    cin >> n >> m >> k;

    cout << what(n, m, k);
}

int greedy(int n, int m, int k) {

    if (k == 0) return 0;

    if (n * m == k) return 0;
    if (n == k || m == k) return 1;

    int leftover = (n * m) - k;
    if (leftover == n || leftover == m) return 1;
    if (leftover < n || leftover < m) return 2;

    int l = lwrbnd(n, k, m);
    int r = lwrbnd(m, k, n);

    int mn = INT_MAX;
    if (l != -1) {
        int sz = n * l;
        mn = min(mn, 1 + greedy(n, m - l, k - sz));
    }

    if (r != -1) {
        int sz = m * r;
        mn = min(mn, 1 + greedy(n - r, m, k - sz));
    }

    return mn;
}

void solve4() {
    int n, m, k;
    cin >> n >> m >> k;

    cout << greedy(n, m, k);
}

vector<pii> factors(int x) {

    vector<pii> ans;

    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.pb({i, x / i});
        }
    }

    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    // possible answers: 0, 1, 2, 3

    // 0 if n * m is already k
    if (n * m == k) {
        cout << 0;
        return;
    }

    int leftover = (n * m) - k;

    // 1 if we can already find i such that n * i == k, or m * i == k
    if ((k % n) == 0 || (k % m) == 0 || (leftover % n) == 0 || (leftover % m) == 0) {
        cout << 1;
        return;
    }

    // 2 if leftover can be put in a square smaller than box
    vector<pii> f = factors(leftover);
    // cout << leftover << '\n';
    for (auto [x, y]: f) {
        // cout << x << ' ' << y << '\n';
        if (x <= n && y <= m) {
            cout << 2;
            return;
        }

        if (y <= n && x <= m) {
            cout << 2;
            return;
        }
    }

    f = factors(k);
    for (auto[x, y]: f) {
        if (x <= n && y <= m) {
            cout << 2;
            return;
        }

        if (y <= n && x <= m) {
            cout << 2;
            return;
        }
    }

    // 3 if. anything else.
    cout << 3;  
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
    