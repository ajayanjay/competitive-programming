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

    vi a(n);
    for (auto & e: a) cin >> e;

    vi pref(n + 1), suf(n + 1);
    pref[0] = 0; suf[n] = 0;
    
    for (int i = 1; i <= n; ++i)
    	pref[i] = min(pref[i - 1] + 1, a[i - 1]);

   	for (int i = n - 1; i >= 0; --i)
   		suf[i] = min(suf[i + 1] + 1, a[i]);

   	int mx = 0;
   	for (int i = 0; i < n; ++i)
   		mx = max(mx, min(pref[i + 1], suf[i]));

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
    