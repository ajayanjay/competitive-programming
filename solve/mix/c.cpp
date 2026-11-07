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

void solve() {

	int n, m;

	cin >> n >> m;

	char treasure[n][m];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> treasure[i][j];

	int q;
	cin >> q;
	while (q--) {
		char temp[n][m];
		mempcpy(temp, treasure, sizeof(char) * n * m);

		int r, c, k;
		cin >> r >> c >> k;

		--c, --r;

		unsigned ll res = 0;

		int i = r, j = c;
		if (temp[i][j] == '1') {
			k--;
			temp[i][j] = '0';
		}

		int cnt = 1;

		while (k > 0) {
			int num = 2 * cnt;

			int pos_i = i + cnt, pos_j = j + cnt;

			if (pos_j < m)
			for (; pos_i > i - cnt; --pos_i) {
				if (k <= 0) break;
				if (pos_i < 0 || pos_i >= n) continue;

				if (temp[pos_i][pos_j] == '1') {
					--k;
					temp[pos_i][pos_j] = '0';
					res += num;
				}
			}

			pos_i = i - cnt;

			if (k <= 0) break;

			if (pos_i >= 0)
			for (; pos_j > j - cnt; --pos_j) {
				if (k <= 0) break;
				if (pos_j < 0 || pos_j >= m) continue;

				if (temp[pos_i][pos_j] == '1') {
					--k;
					temp[pos_i][pos_j] = '0';
					res += num;
				}
			}

			pos_j = j - cnt;
			if (k <= 0) break;

			if (pos_j >= 0)
			for (; pos_i < i + cnt; ++pos_i) {
				if (k <= 0) break;
				if (pos_i < 0 || pos_i >= n) continue;

				if (temp[pos_i][pos_j] == '1') {
					--k;
					temp[pos_i][pos_j] = '0';
					res += num;
				}
			}

			pos_i = i + cnt;
			if (k <= 0) break;

			if (pos_i < n)
			for (; pos_j < j + cnt; ++pos_j) {
				if (k <= 0) break;
				if (pos_j < 0 || pos_j >= m) continue;

				if (temp[pos_i][pos_j] == '1') {
					--k;
					temp[pos_i][pos_j] = '0';
					res += num;
				}
			}


			// for (int x = 0; x < n; ++x) {
			// 	for (int y = 0; y < m; ++y) {
			// 		cout << temp[x][y];
			// 	}
			// 	cout << '\n';
			// }
			// cout << '\n';
			// cout << "Num: " << num << " Res: " << res << '\n';

			cnt++;
		} 
		
		
		cout << res << '\n';
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
    