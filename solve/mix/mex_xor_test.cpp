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

void solve() {
	int q, k;
	cin>> q >> k;

	set<int> s;

	while (q--) {
		int x;
		cin >> x;

		if (s.find(x) != end(s)) { // existing element
			s.erase(x);
		} else { // new element
			s.insert(x);
		}

		int mn = INT_MAX;
		for (int i = 0; i <= k; ++i) {

			vector<bool> vis(200001, false);
			int mex = 0;
			for (auto e : s) {
				int e_xor = e ^ i;

				if (e_xor < 200000) vis[e_xor] = true;

				while (vis[mex]) ++mex;
			}
			mn = min(mn, mex);
		}

		cout << mn << '\n';
	}

	// {0, 1, ..., n}
	// x ^ k == 0 if x == k.
	// 0 1 2 3
	// 0 1 2 3 -> 4
	// 1 0 3 2 -> 4
	// 2 3 0 1 -> 4
	// 3 2 1 0 -> 4
	// 4 5 6 7 -> 0

	// k = 4
	// 0 1 2 3 4 -> 5
	// 1 0 3 2 5 -> 4
	// 2 3 0 1 6 -> 4
	// 3 2 1 0 7 -> 4
	// 4 5 6 7 0 -> 1

	// 0 1 2 3 4 5 -> 6
	// 1 0 3 2 5 4 -> 6
	// 2 3 0 1 6 7 -> 4
	// 3 2 1 0 7 6 -> 4
	// 4 5 6 7 0 1 -> 2
	// 5 4 7 6 1 0 -> 2

	/*
		if i <= k and i doesnt exist in set, the output is 0.
		else
			k == 0 -> current MEX.
			k != 0
				current MEX 
	*/

	

	// 0 1 2 3 4 5 6 -> 7
	// 1 0 3 2 5 4 7 -> 6
	// 2 3 0 1 6 7 4 -> 5
	// 3 2 1 0 7 6 5 -> 4
	// 4 5 6 7 0 1 2 -> 3
	// 5 4 7 6 1 0 3 -> 2
	// 6 ...		 -> 1
	// 7 ...		 -> 0

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