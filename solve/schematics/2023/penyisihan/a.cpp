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

short toPower(char x) {
	switch (x) {
	case '6': return 0;
	case '7': return 1;
	case '8': return 2;
	case '9': return 3;
	case 'T': return 4;
	case 'J': return 5;
	case 'Q': return 6;
	case 'K': return 7;
	case 'A': return 8;
	default: return -1;
	}
}

short toIndex(char c)  {
	switch (c) {
	case 'S': return 0;
	case 'C': return 1;
	case 'D': return 2;
	case 'H': return 3;
	default: return -1;
	}
}

struct _t {
	vector<short> t;

	_t() {
		t = vector<short>(4, -1);
	}
};

bool solve() {
	int n, m;
	char t;
	cin >> n >> m >> t;

	t = toIndex(t);

	_t a, b;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		short pwr = toPower(s[0]);
		short idx = toIndex(s[1]);

		a.t[idx] = max(a.t[idx], pwr);
	}

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;

		short pwr = toPower(s[0]);
		short idx = toIndex(s[1]);

		b.t[idx] = max(b.t[idx], pwr);
	}

	if (a.t[t] > b.t[t]) {
		return true;
	} else {
		return false;
	}

	for (int i = 0; i < 4; ++i) {
		if (i == t) continue;
		if (a.t[i] <= b.t[i]) {
			return false;
		}
	}

	return true;
}

bool solve2() {

	int n, m;
	char t;
	cin >> n >> m >> t;

	t = toIndex(t);

	vector<vector<int>> pA(4), pB(4);  

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		int power = toPower(s[0]);
		int idx = toIndex(s[1]);
		pA[idx].pb(power);
	}

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;

		int power = toPower(s[0]);
		int idx = toIndex(s[1]);
		pB[idx].pb(power);
	}

	vector<int> trufA = pA[t];
	vector<int> trufB = pB[t];

	if (trufA.size() != 0 && trufB.size() == 0) {
		return true;
	}

	if (trufA.size() == 0 && trufB.size() != 0) {
		return false;
	}

	if (trufA.size() != 0 && trufB.size() != 0) {
		int mxA = INT_MIN;
		int mxB = INT_MIN;

		for (auto e : trufA) {
			mxA = max(mxA, e);
		}

		for (auto e : trufB) {
			mxB = max(mxB, e);
		}

		if (mxA > mxB) {
			return true;
		} else {
			return false;
		}
	}

	// both is 0.
	for (int i = 0; i < 4; ++i) {
		if (i == t) continue;

		int mxA = INT_MIN;
		int mxB = INT_MIN;

		for (auto e : pA[i]) {
			mxA = max(mxA, e);
		}

		for (auto e : pB[i]) {
			mxB = max(mxB, e);
		}

		if (mxA > mxB) {
			continue;
		} else {
			return false;
		}
	}

	return true;
}

signed main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    return 0;
}
    