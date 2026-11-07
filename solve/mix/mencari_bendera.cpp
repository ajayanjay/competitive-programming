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

#define MOD 1000000000000000000

void solve() {
	int n, m;
	cin >> n >> m;

	ll ml = 0;
	for (int i =0 ; i < m; ++i ) {
		int c, h, k;
		cin >> c >> h >> k;

		ll totalBarang = n * k;
		ll totalPaket = (totalBarang / c) + (totalBarang % c == 0 ? 0 : 1);
		ll totalHarga = (totalPaket * h) % MOD;

		ml = (ml + totalHarga) % MOD;
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
    