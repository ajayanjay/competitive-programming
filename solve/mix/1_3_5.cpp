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

    int lib[3] = {1, 3, 5};

    int x = 0, y = 0, z = 0;

    for (x = 0; x * lib[0] <= n; ++x) {
    	int x1 = x * lib[0];
    	for (y = 0; (x1 + y * lib[1]) <= n; ++y) {
    		int y1 = x1 + y * lib[1];

    		int n1 = n - y1;

    		if (n1 % lib[2] == 0) {
    			cout << x << '\n';
    			return;
    		}
    	}
    }
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
