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
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n), b(m);

    for (auto & e : a)
    	cin >> e;

    for (auto & e : b)
    	cin >> e;

    for (int i = 0; i < k; ++i) {
    	int i_n = i % n;
    	int i_m = i % m;

    	if (a[i_n] > b[i_m]) {
    		swap(a[i_n], b[i_m]);
    	}
    }

    for (auto e : a) 
    	cout << e << ' ';

    cout << '\n';

    for (auto e : b)
    	cout << e << ' ';
    
    cout << '\n';
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
    