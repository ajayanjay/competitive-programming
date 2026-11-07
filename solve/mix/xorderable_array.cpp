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


    vi a(n);
    vi x(m);

    for (auto & e : a )
    	cin >> e;

    for (auto & e : x)
    	cin >> e;

    ll res = 0;
    for (int i = 0; i < m - 1; ++i) {
    	for (int j = i + 1; j < m; ++j) {
    		
    		vector<pair<int, int>> t_a(n);

    		for (int k = 0; k < n; ++k) {
    			t_a[k].first = a[k] ^ x[i];
    			t_a[k].second = a[k] ^ x[j];
    		}

    		sort(all(t_a), [] (pair<int, int> & a, pair<int,int> & b) {
    			return a.first <= b.second && a.second <= b.first;
    		});

    		bool f = true;
    		for (int k = 0; k < n - 1; ++k) {
    			for (int l = k + 1; l < n; ++l) {
    				if (t_a[k].first > t_a[l].second || t_a[k].second > t_a[l].first) {
    					f = false;
    					break;
    				}

    				if (!f) break;
    			}
    			if (!f) break;
    		}

    		if (f) {
    			++res;
    		}

    	}
    }

    cout << res;

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
    