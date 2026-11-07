#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

const int MD = 998244353;
const int MAXN = 1e6;

int f[MAXN + 1], invf[MAXN + 1];

int modpow(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1)
            r = r * a % MD;
        a = a * a % MD;
        e >>= 1;
    }
    return r;
}

void precmp() {

    f[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        f[i] = (f[i-1] * i) % MD;

    invf[MAXN] = modpow(f[MAXN], MD - 2);
    for (int i = MAXN; i > 0; --i)
        invf[i - 1] = invf[i] * i % MD;
}

int mulmod(int a, int b) {
    return a * b % MD;
}

int addmd(int a, int b) {
    return a + b % MD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return f[n] * invf[r] % MD * invf[n - r] % MD;
}

int nPr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return f[n] * invf[n - r] % MD;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int a = modpow(m, ((n + 1) / 2) + 1);
    int b = modpow(m, ((n / 2)) + 1);
    int c = mulmod(n, m);
    int res = addmd(addmd(a, b), c);
    cout << a << ' ' << b << ' ' << c << '\n';
    cout << res;



}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precmp();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "YES\n";
        // else cout << "NO\n";
    }
}