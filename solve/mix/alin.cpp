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

pair<vector<double>, double> solve_spl(vector<vector<double>> a, vector<double> b) {

	double det = 1;

	for (int i = 0; i < 4; ++i) {

		if (a[i][i] == 0) {
			// try find replacement.
			for (int j = i + 1; j < 4; ++j) {
				if (a[j][i] != 0) {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
					break;
				}
			}

			if (a[i][i] == 0)
				return {{}, 0}; // spl homogen heheheha
		}

		for (int j = i + 1; j < 4; ++j) {
			if (a[j][i] == 0) continue;
			double ratio = (double) a[j][i] / (double) a[i][i];

			a[j][i] = 0;
			b[j] -= ratio * b[i];

			for (int k = i + 1; k < 4; ++k) {
				a[j][k] -= ratio * a[i][k];
			}
		}

		det *= a[i][i];
	}

	for (int i = 3; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[j][i] == 0) continue;
			double ratio = (double) a[j][i] / (double) a[i][i];

			a[j][i] = 0;
			b[j] -= ratio * b[i];
		}

		b[i] /= a[i][i];
		a[i][i] = 1;
	}

	return {b, det};
}

void solve() {
    vector<vector<double>> m(4, vector<double>(4));
    vector<double> f(4);

    for (int i = 0; i < 4; ++i) 
    	for (int j = 0; j < 4; ++j)
    		cin >> m[i][j];


    for (int i = 0; i < 4; ++i)
    	cin >> f[i];

    auto[t, d] = solve_spl(m, f);

    if (d == 0) {
    	cout << "NO UNIQUE SOLUTION\n";
    } else {
    	for (auto c : t)
    		cout << c << ' ';
    }
}

int main() {
    // fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}