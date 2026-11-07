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

bool solve2() {
	int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    vector<bool> safe(m);

    bool has1 = false;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j ) {
    		int e;
    		cin >> e;

    		if (e == 1) {
    			has1 = true;
    			safe[j] = true;
    		}
    	}
    }

    if (n < 2 || m < 2) {
    	return has1;
    }

    return true;
}

bool solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n, vector<bool>(m));
    vector<bool> hor(n), ver(m);

    bool has1 = false;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		bool e;
    		cin >> e;

    		a[i][j] = e;

    		if (e) {
    			has1 = true;
    			hor[i] = true;
    			ver[j] = true;
    		}
    	}
    }

    if (!has1) return false;

    if (n < 2 || m < 2) {
    	return has1;
    }

    for (int i = 0; i < n; ++i) {
        if (!hor[i]) continue;
    	for (int j = 0; j < m; ++j) {
    		if (!a[i][j] && ver[j]) return false;
    	}
    }

    /*
	xor
	1 1 | 0
	1 0 | 1
	0 1 | 1
	0 0 | 0
    */

    return true;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "1";
        else cout << "0";
    }
    return 0;
}
    