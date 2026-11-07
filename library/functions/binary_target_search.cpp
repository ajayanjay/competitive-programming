#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr, int target, int k) {
	return arr[target] >= k;
}

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &e: a) 
		cin >> e;

	sort(a.begin(), a.end());

	int ans;
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (possible(a, m, k)) {
			r = m - 1;
			ans = m;
		} else {
			l = m + 1;
		}
	}

	cout << ans;
}