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
#define ull unsigned ll

bool solve() {
    ull n, a, b;
    cin >> n >> a >> b;

    if (a != b) {
    	return false;
    } else {
    	for (int i = 1; i < 64; ++i) {
    		int next = (n & (1 << (i + 1)));
    		int curr = (n & (1 << i));
    		int prev = (n & (1 << (i - 1)));

    		if (prev && !curr && next) return false;
    	}

    	return true;
    }
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
    