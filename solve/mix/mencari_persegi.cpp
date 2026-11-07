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
#define ull unsigned ll
#define MOD 1000000007

long long binpow(long long a, long long b, long long mod = MOD) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void solve2() {
    ll n, m;
    cin >> n >> m;

    if (n < 2 || m < 2) {
    	cout << 0;
    	return;
    }

    // bruteforce
    // ull sq = 0;
    // ll mn = min(n, m);
    // for (ll i = 1; i < mn; ++i) {
    // 	if (i == 1)
    // 		sq += ((n - i) * (m - i)) % MOD;
    // 	else
    // 		sq += ((n - i) * (m - i)) * 2 % MOD;
    // }

    // cout << sq % MOD;


    /*
	2x2 -> (n - 1) * (m - 1)
	3x3 -> (n - 2) * (m - 2)
	axa -> (n - a) * (m - a) for all a 

	---

	diagonal square
	2x2 -> (n - 2) * (m - 2)
	axa -> (n - (a + 1)) * (n - (a + 1)) for all a

	---

	bisa di gabung..
	2x2 vertical sama diagonal di posisi yang sama = x2

	i = 2..min(n, m)
	sum((n - i) * (m - i) * 2)
	=
	2 * sum(n * m - n * i - m * i + i * i)
	=
	2 * (
		sum(n * m)
		- sum(i * (n + m))
		+ sum(i * i)
	)
	=
	2 * (
		(n * m * min(n, m))
		- (n + m) * i * (i + 1) / 2
		+ i * (i + 1) * (2 * i + 1) / 6
	)
    */

    // mod madness
    ull res = (n - 1) % MOD
     * (m - 1) % MOD;

    ull mn = min(n, m);

    ull n_m = (n % MOD * m % MOD * mn % MOD);
    ull n_sub_m = ((n + m) % MOD * mn % MOD * (mn + 1) % MOD) / 2;
    ull i_i = (mn % MOD * (mn + 1) % MOD * (2 * mn + 1) % MOD) / 6;

    // cout << "first: " << res << '\n';
    // cout << "(n * m * mn): " << n_m << '\n';
    // cout << "(n + m) * sum (i): " << n_sub_m << '\n';
    // cout << "sum(i ^ 2): " << i_i << '\n';

    res = (2 * ((((n_m + i_i) % MOD) - n_sub_m) % MOD)) % MOD - res;
    cout << res % MOD;
}

ll modinv(int a) {
    return binpow(a, MOD - 2);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    if (n < 1 || m < 1) {
        cout << 0;
        return;
    }

    // square
    /*
        a = min(n, m)
        1 -> (n - 1) * (m - 1)
        2 -> (n - 2) * (m - 2)
        3 -> (n - 3) * (m - 3)
        a -> (n - a) * (m - a)

        sq -> sum{1..a} (n - i) * (m - i)
        sq -> sum (nm - in - im + i^2)
        sq -> anm 
            -> - (n + m) * i * (i + 1) / 2
            -> + i * (i + 1) * (2 * i + 1) / 6
    */

    ll a = min(n, m);

    ll sq = 0;
    sq = (sq + a * n * m) % MOD;
    sq = (sq - (n + m) * a * (a + 1) * modinv(2) + MOD) % MOD;
    sq = (sq + a * (a + 1) * (2 * a + 1) * modinv(6)) % MOD;

    // diamond
    /*
        3, 5, 7...
        only odd... (exlcluding 1)
        2, 3, 4, ...

        a = min(n, m)
        a = a / 2
        do the same again.
        
        3 3
        a = 1

    */

    if (n <= 2 || m <= 2) {
        cout << sq;
        return;
    }

    n = (n / 2) + 1, m = (m / 2) + 1;
    a = min(n, m);

    ll dm = 0;
    dm = (dm + a * n * m) % MOD;
    dm = (dm - (n + m) * a * (a + 1) * modinv(2) + MOD) % MOD;
    dm = (dm + a * (a + 1) * (2 * a + 1) * modinv(6)) % MOD;

    cout << "Square:" << sq << " Diamond:" << dm << '\n';

    cout << (sq + dm) % MOD;
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
    