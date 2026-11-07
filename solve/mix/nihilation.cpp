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
    
    int g = 0;
    for (int i = 0; i < n; ++i) {
    	int e; cin >> e;
    	g = gcd(g, e);
    }

    if (g > 1)
    	cout << 1 << '\n' << g << ' ' << 1;
    else
    	cout << 2 << '\n' << 4 << ' ' << 2 << '\n' << 4 << ' ' << 2;
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
