#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define MAX_K 1000000000000
#define MAX_N 26

void prcmp(vector<vll> &t, vector<vi> &m, ll n) {

	ll sz = t.size();
	for (int i = 0 ; i < sz; ++i) {
		for (int j = 0; j < MAX_N; ++j) {
			t[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_N; ++i) {
		t[0][i] = 1; // 0 q -> 1
	}

	for (int i = 1; i < sz; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int c : m[j]) {
				if (c >= n) // out of bound
					t[i][j]++;
				else
					t[i][j] += t[i - 1][c];

				if (t[i][j] > MAX_K) {
					t[i][j] = MAX_K;
					break;
				}
			}
		}
	}

	// for (int i = 0; i < sz; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cout << t[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
}

void solve() {
	ll n, k, q;
	cin >> n >> k >> q;

	string s;
	cin >> s;

	vector<vll> tree(q + 1, vll(MAX_N));
	vector<vi> m(n);

	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;

		for (char c: t) {
			m[i].push_back(c - 'A');
		}
	}

	prcmp(tree, m, n);
	ll j = q;

	// walk started at the very bottom
	ll currentChar = -1;
	ll acc = 0;
	while (j >= 0) {

		// cout << j << ' ' << (char) (currentChar + 'A') << '\n';	

		if (j == q) {
			for (char c : s) {
				c -= 'A';

				ll ad = (c >= n ? 1 : tree[j][c]);
				if (acc + ad >= k) {
					--j;
					currentChar = c;
					break;
				} else {
					acc += ad;
				}
			}

			if (currentChar == -1) break;
			else continue;
		}

		for (int c : m[currentChar]) {
			ll ad = (c >= n ? 1 : tree[j][c]);
			if (acc + ad >= k) {
				--j;
				currentChar = c;
				break;
			} else {
				acc += ad;
			}
		}

	}

	if (j == q) {
		cout << "Ga ada, Mas";
	} else {
		cout << (char) (currentChar + 'A');
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
    