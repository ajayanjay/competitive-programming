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
    int n, q;
    cin >> n >> q;

    char module[n];
    int k[n];

    unsigned ll results[n];

    ll res = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> module[i] >> k[i];

    	if (module[i] == '+') {
    		res = (res + k[i]) % 16;
    	} else {
			res = res ^ k[i];
    	}
    	results[i] = res;
    }

    while (q--) {
    	int idx, num;
    	char modul;
    	cin >> idx >> modul >> num;

    	--idx;

    	module[idx] = modul;
    	k[idx] = num;

    	if (idx == 0) {
    		ll res = 0;
    		for (int i = 0; i < n; ++i) {
    			if (module[i] == '+') {
		    		res = (res + k[i]) % 16;
		    	} else {
					res = res ^ k[i];
		    	}
		    	results[i] = res;
    		}
    	} else {
    		for (int i = idx; i < n; ++i) {
    			if (module[i] == '+') {
    				results[i] = (results[i - 1] + k[i]) % 16;
    			} else {
    				results[i] = results[i - 1] ^ k[i];
    			}
    		}
    	}

    	// int res = 0;
    	// for (int i = 0; i < n; ++i) {
    	// 	if (i == idx) {
    	// 		if (modul == '+') {
    	// 			res = (res + num) % 16;
    	// 		} else {
    	// 			res = res ^ num;
    	// 		}


    	// 	} else {
    	// 		if (module[i] == '+') {
    	// 			res = (res + k[i]) % 16;
    	// 		} else {
    	// 			res = res ^ k[i];
    	// 		}
    			
    	// 	}
    	// }

    	cout << results[n - 1] << '\n';
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
    