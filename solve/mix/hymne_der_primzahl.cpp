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

bool isPrime(ll n) {
	if (n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}

	return true;
}

void solve() {
 	ll l, r;
 	cin >> l >> r;

 	int cnt = 0;
 	vll a;

 	

 	cout << cnt << '\n';
 	for (ll e : a)
 		cout << e << ' ';
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
    