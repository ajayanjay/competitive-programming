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
    int n;
    cin >> n;

    int smA = 0, smB = 0;

    for (int i  =0 ; i < n; ++i) {
    	int e;
    	cin >> e;
    	smA += e;
    }

    for (int i = 0; i < n; ++i) {
    	int e;
    	cin >> e;
    	smB += e;
    }

    if (smA > smB) {
    	cout << "Pak Chanek";
    } else if (smA < smB) {
    	cout << "Pak Ganesh";
    } else {
    	cout << "Mabar";
    }


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
    