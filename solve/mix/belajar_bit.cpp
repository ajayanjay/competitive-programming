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

bool solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    
    for (int i = 0; i < n; ++i) {
    	cin >> a[i] >> b[i];
    	++a[i]; // shift by one.
    }

    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
    	if (res == 0) { // res = 0, fill up.
    		res = (b[i] % 2);
    	} else { // res != 0, try subtract
    		/*
				res = 2 * res
				while (res > 0 && b[i] > 0)
					res -= a[i]
					--b[i]

				if (res == 0, b[i] == 0) continue
				if (res > 0, b[i] == 0) continue.
				if (res == 0, b[i] > 0)
					res = (b[i] % 2) * a[i]
    		*/
    		int diff = a[i + 1] - a[i];
    		int what = floor(log2(res));
    		if (diff + what > 31) return false; // evil hack

    		res <<= diff; 

    		int subB = min(res, b[i]);
    		b[i] -= subB;
    		res -= subB;

    		if (b[i] > 0)
    			res = (b[i] % 2);

    	}

    	// cout << res << '\n';
    }

    return res == 0;
}

signed main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    return 0;
}
    