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

ll what(int i, int n) {
	++i; // 1-indexed

	if (i > (n / 2 + (n % 2 == 0 ? 0 : 1))) {
		i = n - i + 1;
	}

	ll sm = i * (i + 1) / 2; 	// sum 1..i
	sm += (n - i - 1) * i;		// 
	sm += 1;					// 
	return sm;
}

long long binpow(long long a, long long b, ll mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int coprime(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (gcd(n, i) == 1) 
		++cnt;
	
	return cnt;
}

void solve() {
    int n;
    cin >> n;

    int MOD = 1e9 + 7;

    vi a(n), cp(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	cp[i] = coprime(a[i]);

    }

    ull ml = 1;
    for (int i = 0; i < n; ++i) {
    	ml = (ml * binpow(cp[i], what(i, n), MOD)) % MOD;
    }

    cout << ml;
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
    