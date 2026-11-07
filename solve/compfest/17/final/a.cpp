#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n, m;
    cin >> n >> m;

    int f = n * m;
    int s;
    int res;
	int g = gcd(n, m);

	// 6 : 4 -> 3 : 2 -> 9 : 6

	if (g == 1) {
		n *= 2;
		m *= 2;
		s = n * m;
		res = s - f;
	} else {
		int n2 = n / g;
		int m2 = m / g;

		// 6 : 4 -> 2, 6 / 2 = 3, 4 / 2 = 2, 

		n = n2 * (g + 1);
		m = m2 * (g + 1);

		s = n * m;
		res = s - f;
	}

	cout << res;
}

signed main() {
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
    