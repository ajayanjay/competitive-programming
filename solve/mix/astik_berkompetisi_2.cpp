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

const ll N = 1048576 + 1;
const ll mod = 1000000007;

ll fact[N], invfact[N];

ll mul(ll a, ll b) {
    return (1LL * a * b) % mod;
}

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) {
            res = mul(res, x);
        }
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}

void precmp() {
    fact[0] = 1;
    ll i;
    for (i = 1; i < N; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
    i--;
    invfact[i] = power(fact[i], mod - 2);
    for (i--; i >= 0; i--) {
        invfact[i] = mul((i + 1), invfact[i + 1]);
    }
}

int ncr(int n, int r) {
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}

int npr(int n, int r) {
	if (r > n || n < 0 || r > 0)
		return 0;
	return mul(fact[n], invfact[r]);
}

void solve() {
	ll n, k;
	cin >> n >> k;

    ll res = floor(log2(k)) + 1;
    ll slot;
    if (res > n) {
    	res = n;
    	slot = (1 << n) - 1;
    } else {
    	slot = (1 << (res - 1)) - 1;
    }

    // only work on power of 2
    ll tp = (1 << n);
    ll less = k - 1;
    ll more = tp - k;
    ll available = less - slot;
    ll remaining = more + available;

    // cout << "slot: " << slot << " less: " << less << " available: " << available << ' ';

    ll r1 = ncr(less, slot);
    ll r2 = fact[remaining];
    ll r3 = fact[slot];
    ll r4 = tp;

    // cout << r1 << '|' << r2 << '|' << r3 << '|' << r4 << ' ';

    ll res2 = r1;
    res2 = mul(res2, r2);
    res2 = mul(res2, r3);
    res2 = mul(res2, r4);

    cout << res << ' ' << res2 << '\n';

}

int main() {
    fast_io;
    precmp();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    