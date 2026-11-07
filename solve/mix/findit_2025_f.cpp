f.cpp
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
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    return fact[n] * invf[r] % MOD * invf[n - r] % MOD;
}

void solve(){
    int n, m, l, r; cin >> n >> m >> l >> r;

    if (l * m > n) {
        cout << 0 << "\n";
        return;
    }

    int w = r - l + 1;
    int mungkin = (n - m * l) / w;
    int cara = 0;

    for(int k = 0; k <= mungkin && k <= m; ++k){
        int j = n - m * l - k * w;
        int term = (nCr(m, k) * nCr(j + m, j)) % MOD;

        cara = k & 1 ? (cara - term + MOD) % MOD : (cara + term) % MOD;
    }

    if(l == 1) cara = (cara - 1 + MOD) % MOD;
    cout << (cara * nCr(n, m)) % MOD << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precmp(1000005);

    int t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}