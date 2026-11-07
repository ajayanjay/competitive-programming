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
	int l, r, u, d;
};

int minFour(_t a) { // returns index 0 - 3.

    int mn = INT_MAX;

    mn = min(mn, a.l);
    mn = min(mn, a.r);
    mn = min(mn, a.u);
    mn = min(mn, a.d);

    return mn;

}

_t minT(_t a, _t b) {
	return {
		.l = min(a.l, b.l),
		.r = min(a.r, b.r),
		.u = min(a.u, b.u),
		.d = min(a.d, b.d)
	};
}

int trapRainWater(vector<vector<int>>& a) {
	int n = a.size();
	int m = a[0].size();

	vector<vector<_t>> mx(n, vector<_t>(m, {INT_MIN, INT_MIN, INT_MIN, INT_MIN})); // a precompute of 'max'
	vector<vector<bool>> isPillar(n, vector<bool>(m, false));
	vector<vector<bool>> vis(n, vector<bool>(m, false));

	for (int j = 0 ; j < m; ++j) {
		mx[0][j].u = a[0][j];
		isPillar[0][j] = true;
	}

	for (int j = m - 1; j >= 0; --j) {
		mx[n - 1][j].d = a[n - 1][j];
		isPillar[n-1][j] = true;
	}

	for (int i = 0; i < n; ++i) {
		mx[i][0].l = a[i][0];
		isPillar[i][0] = true;
	}

	for (int i = n - 1; i >= 0; --i) {
		mx[i][m - 1].r = a[i][m - 1];
		isPillar[i][m - 1] = true;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (j != 0)
				mx[i][j].l = max(a[i][j], mx[i][j - 1].l);

			if (i != 0)
				mx[i][j].u = max(a[i][j], mx[i - 1][j].u);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (j != m - 1)
				mx[i][j].r = max(a[i][j], mx[i][j + 1].r);			

			if (i != n - 1)
				mx[i][j].d = max(a[i][j], mx[i + 1][j].d);
		}
	}

	int water = 0;

	auto click = [&](auto& self,int i, int j) -> _t {
		if (vis[i][j]) return mx[i][j];
		vis[i][j] = true;

		if (isPillar[i][j]) return mx[i][j];
		if (minFour(mx[i][j]) == a[i][j]) {
			isPillar[i][j] = true;
			return mx[i][j];
		}

		_t curr = mx[i][j];

		if (!vis[i][j - 1]) { // if not come from left, go left
			_t x = self(self, i, j - 1);
			curr = minT(curr, x);
		}

		if (!vis[i][j + 1]) { // if not come from right, go right
			_t x = self(self, i, j + 1);
			curr = minT(curr, x);
		}

		if (!vis[i - 1][j]) { // not up, go up
			_t x = self(self, i - 1, j);
			curr = minT(curr, x);
		}

		if (!vis[i + 1][j]) { // not down, go down
			_t x = self(self, i + 1, j);
			curr = minT(curr, x);
		}

		return curr;
	};

	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {

			int mf = minFour(mx[i][j]);
			int e = a[i][j];

			if (mf == e) {
				isPillar[i][j] = true;
				continue;
			}

			vis.assign(n, vector<bool>(m, false));

			_t res = click(click, i, j);
			isPillar[i][j] = true;
			mf = minFour(res);
			e = a[i][j];

			int diff = mf - e;
			water += max(diff, 0);

			cout << i << j << ' ' << diff << '\n';

		}
	}

	// for (auto x : mx) {
	// 	for (auto e : x) {
	// 		cout << e.l << ':' << e.r << ':' << e.u << ':' << e.d << ' ';
	// 	} 
	// 	cout << '\n';
	// }

	return water;

}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));

    for (auto &x : a)  {
    	for (auto &e : x) {
    		cin >> e;
    	}
    }

    cout << trapRainWater(a);
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
    