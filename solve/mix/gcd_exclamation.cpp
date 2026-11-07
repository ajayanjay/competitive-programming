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

void solve(int n, int k) {
	int res = 1;

	int i = 2;
	while (k % i == 0) {
		k /= i;
		res *= i;
	}

	for (i = 3; i <= n; i += 2) {
		if (i > k) break;
		while (k % i == 0) {
			k /= i;
			res *= i;
		}
	}

	cout << res << '\n';
}

signed main() {
    fast_io;
    int t = 1;
    // cin >> t;
    int n, k;
    while (cin >> n >> k) {
    	solve(n, k);

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    