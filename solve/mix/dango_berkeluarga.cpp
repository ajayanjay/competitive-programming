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

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    int r = 0, l = INT_MIN;
    for (auto &e: a){
    	cin >> e;
    	r += e;
        l = max(l, e);
    }

    while (l < r) {
    	int m = l + (r - l) / 2; // m is the minimum domination

        // cout << l << ':' << m << ':' << r << '\n';
    	// check if m is possible

        int currSum = a[0];
        int currK = n;
        for (int i = 1; i < n; ++i) {

            if (currK == k) break;

            if (currSum + a[i] > m) {
                currSum = a[i];
            } else {
                currSum += a[i];
                currK -= 1;
            }
        }

    	// if not try higher value
    	// if yes try lower value

        bool possible = currK == k;

    	if (possible) r = m;
    	else l = m + 1;
    }

    cout << l;
}

signed main() {
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
