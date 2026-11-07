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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    bool isOne = false;
    bool isZero = false;

    int mn = 0, mx = 0;

    for (auto c : s) {
    	if (c == '1') {
    		isOne = true;
    		if (isZero) {
    			isZero = false;
    			++cnt;
    		}
    		++cnt;
    	} else if (isOne) {
    		isZero = true;
    		isOne = false;
    	} else {
    		isOne = false;
    		isZero = false;

    		if (cnt != 0) {
    			mn += (cnt / 2) + 1;
	    		mx += cnt;
	    		cnt = 0;
    		}
    	}
    }

    if (cnt != 0) {
    	mn += (cnt / 2) + 1;
    	mx += cnt;
    }

    cout << mn << ' ' << mx << '\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
