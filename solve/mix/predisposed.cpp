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

long long binpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int MOD =  998244353;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    int __, _ = q;
    while (_--) cin >> __ >> __;
    cout << binpow(m, n - q, MOD);
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
    