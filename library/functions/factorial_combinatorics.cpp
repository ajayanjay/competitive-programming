const int N = 1000001;
const int mod = 1000000007;

int fact[N], invfact[N];

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int power(int x, int y) {
    int res = 1;
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
    int i;
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
