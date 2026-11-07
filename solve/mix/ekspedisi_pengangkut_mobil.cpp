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

struct _t {
	short c, l, s, u, r;
};

void solve() {
    int n, p;
    cin >> n >> p;

    vector<_t> ships(n);
    for (auto &[c, l, s, u, r] : ships)
    	cin >> c >> l >> s >> u >> r;
    // r + l + s + u -> c
    // l + s + u -> c

    // change the question into:
    /*
		given a time t[i], and a weight c[i];
		return the minimum time it takes to get P total cart from all ships.

		ll TimePerCart = t[i] / c[i];
		ll maxTime = highest TimePerCart * total cart [t[i] * p]
		ll minTime = lowest TimePerCart * total cart [t[i] * p]

		ll left = minTime
		ll right = maxTime

		while (left < right) {
			ll mid = left + (right - left) / 2; -> middle time

			mission: determine whether middle time is POSSIBLE.
			by possible -> the sum of c[i] over mid is sufficient
				for (auto[t, c]: ships)
					sm += (mid / t) * c

			if possible -> try lower value, move right to mid
			else -> try higher value, move left to mid
				if sm > P
					right = mid;
				else
					left = mid;
		}

		it would be all sunshine and rainbow if not for the fact that
		we started at L S U and then do R L S U.

		4e2 * 1e9 = 4e11
    */

    ll l = 1;
    ll r = 4e11; // maximum possible time s: [1, 100, 100, 100, 100] * P: 1e9
    while (l < r) {
    	ll m = l + (r - l) / 2;

    	ll sm = 0;
    	for (auto[c, l, s, u, r]: ships) {

    		// first:
    		ll first = l + s + u;
    		if (first > m) continue;
    		sm += c;

    		// second and until last.
    		ll second = r + l + s + u;

    		// variable m: maximum time
    		// total cycle = m / second - 1
    		ll tc = max(((m - first) / second), (ll) 0); // -1 due to first cycle
    		sm += tc * c;
    	}

    	if (sm < p) // sum is lower than p
    		l = m + 1; // try higher value
    	else // sum is higher than p, can be squeezed more.
    		r = m; // try lower value
    }

    cout << l;
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
    