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
    vi a(3);
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    int x = 0, y = 0, z = 0;

    int mx = 0;

    if (n % a[0] == 0) {
    	mx = n / a[0];
    } else if (n % a[1] == 0) {
    	mx = n / a[1];
    } else if (n % a[2] == 0) {
    	mx = n / a[2];
    }

    for (x = 0; a[2] * x <= n; ++x) {
    	int x1 = x * a[2];
    	for (y = 0; (x1 + a[1] * y) <= n; ++y) {
    		int y1 = x1 + y * a[1];

    		int n1 = n - y1;
    		if (n1 % a[0] == 0) {
    			z = n1 / a[0];
    			mx = max(mx, x + y + z);
    		}
    	}

    	y = 0;
    }

    cout << mx;
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
    