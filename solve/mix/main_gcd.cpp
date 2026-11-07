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

long long binpowmod(long long a, long long b, ll M) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res % M;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (auto &e : a)
    	cin >> e;

    const int M = 998244353;
    ull res = 1;

    // i < j, mul gcd ai aj

    for (int i = 0; i < n - 1; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		res = (res * gcd(a[i], a[j])) % M;
    	}
    }

    

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
