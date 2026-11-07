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

#define MAX_N 101

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	int diff[MAX_N] = {0};
	int prefSum[MAX_N] = {0};

	for (int i = 0 ; i < n; ++ i) {
		int l, r;
		cin >> l >> r;

		++diff[l];
		--diff[r + 1];
	}

	int cnt = 0;

	for (int i = 1; i < MAX_N; ++i) {
		cnt += diff[i];
		prefSum[i] = prefSum[i - 1] + (cnt  >= k ? 1 : 0);
	}

	while(q--) {
		int l, r;
		cin >> l >> r;

		cout << prefSum[r] - prefSum[l - 1] << '\n';
	}
}

void solve2() {
 
	int n, k, q;
	cin >> n >> k >> q;

	int diff[MAX_N] = {0};

	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;

		diff[l] += 1;
		diff[r + 1] -= 1;
	}

	int processed[MAX_N] = {0};
	int prefSum[MAX_N] = {0};

	for (int i = 1; i < MAX_N; ++i) {
		processed[i] = processed[i - 1] + diff[i];

		prefSum[i] = prefSum[i - 1] + (processed[i] >= k ? 1 : 0);

		// cout << i << ' ' << processed[i] << ' ' << prefSum[i] << '\n';
	}


	while (q--) {
		int a, b;
		cin >> a >> b;

		cout << prefSum[b] - prefSum[a - 1] << '\n';
	}

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
    