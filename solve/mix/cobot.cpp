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
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    string res(s);

    for (int i = 0 ; i < n; ++i)
    	res[i] = '.';

    for (int i = 0; i < n; ++i) {
    	char c = s[i];

    	if (c == 'R') {
    		if (i + t < n) 
    			res[i + t] = 'X';
    	} else {
    		if (i - t >= 0)
    			res[i - t] = 'X';
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
    