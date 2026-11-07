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

    vector<vi> p(n, vi(m));

    for (auto &x : p) 
    	for (auto &e : x) 
    		cin >> e;

    int acc = 0;
    for (int i = 0; i < n; ++i) {

    	int c = 0;
    	bool f = false;
    	
    	for (int j = 0; j < m; ++j) {
    		if (p[i][j] == 1) {
    			f = true;
    			continue;
    		}

    		if (f) ++c;
    	}

    	acc += c;

    	c = 0;
    	f = false;
    	for (int j = m - 1; j >= 0; --j) {
			if (p[i][j] == 1) {
    			f = true;
    			continue;
    		}

    		if (f) ++c;
    	}

    	acc += c;
    }

    for (int j = 0; j < m; ++j) {
    	int c = 0;
    	bool f = false;
    	
    	for (int i = 0; i < n; ++i) {
    		if (p[i][j] == 1) {
    			f = true;
    			continue;
    		}

    		if (f) ++c;
    	}

    	acc += c;

    	c = 0;
    	f = false;
    	for (int i = n - 1; i >= 0; --i) {
			if (p[i][j] == 1) {
    			f = true;
    			continue;
    		}

    		if (f) ++c;
    	}
    	acc += c;
    }

    cout << acc;

    // dy[i] = total 0 on y[i]
    // dx[i] = total 0 on x[i]
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
    