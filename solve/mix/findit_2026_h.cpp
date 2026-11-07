h.cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int MOD = 998244353;

vector<int> fact, invf;

int modpow(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int modinv(int n) {
    return modpow(n, MOD - 2);
}

void precmp(int n) {
    fact.assign(n + 1, 1);
    invf.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
   
    invf[n] = modinv(fact[n]);
    for (int i = n - 1; i >= 1; i--) {
        invf[i] = (invf[i + 1] * (i + 1)) % MOD;
    }
}

int nCr(int n, int r) {
    if (r <  0 || r >  n) return 0;
    if (r == 0 || r == n) return 1;
    return fact[n] * invf[r] % MOD * invf[n - r] % MOD;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(m == 1){
        int sum = 0;
        for(int i = 0; i < n; ++i) sum = (sum + a[i]) % MOD;
        int mean = (sum * modinv(n)) % MOD;
        cout << mean << '\n';
        return;
    }

    sort(a.rbegin(), a.rend());
   
    int res = a[0];
    int sum = 0;

    // pdf apa hg? gabugn?
    for (int k = 1; k < n; ++k) {
        int diff = (a[n - k - 1] - a[n - k] + MOD) % MOD;

        int k1 = nCr(n, k - 1);
        int k2 = (n - k) * nCr(n - m + 1, k - m) % MOD;
       
        int nn = (k1 + k2) % MOD;
        int dn = nCr(n, k);
        int bk = nn * modinv(dn) % MOD;

        int cur = diff * bk % MOD;
        sum = (sum + cur) % MOD;
    }

    int expc = sum * modinv(n) % MOD;
    res = (res - expc + MOD) % MOD;

    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precmp(1000005);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}