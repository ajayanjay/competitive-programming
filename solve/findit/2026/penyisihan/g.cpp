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
#define MOD 1000000007
#define spc ' '

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

ll sigsum(ll n) {
    if (n <= 0) return 0;
    n %= MOD;
    return n * (n + 1) % MOD * ((MOD + 1) / 2) % MOD;
}

void solve() {
    ll n;
    cin >> n;

    // base spaces
    ll start = (binpow(2, n + 1) - 1 + MOD) % MOD;
    ll half = binpow(2, n);
    ll end = half;

    // total spasi tanpa segitiga
    ll smSpace = ((sigsum(start) - sigsum(end - 1)) % MOD + MOD) % MOD;

    // cout << "total spaces: " << sm << '\n';

    // triangle
    ll smTriangle = 0;
    // 1 -> 3
    // 2 -> (1 * 3) -> 3 x 3 -> 9
    // 3 -> (2 * 3) -> 9 x 3 = 27.
    smTriangle = binpow(3, n);

    // hasilnya total spasi - total bintang
    ll res = ((smSpace - smTriangle) % MOD + MOD) % MOD;
    cout << res;
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
    

/*
   *
  * *
 *   *
* * * *

13 spaces

---
       *
      * *
     *   *
    * * * *
   *       *
  * *     * *
 *   *   *   *
* * * * * * * *
65 spaces

*/