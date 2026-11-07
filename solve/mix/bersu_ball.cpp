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

#define MAXN 100

void solve() {
 	int n;
 	cin >> n;
 	
 	vi a(MAXN + 2, 0);
 	for (int i = 0; i < n; ++i) {
 		int e;
 		cin >> e;

 		++a[e];
 	}

 	int m;
 	cin >> m;

 	vi b(MAXN + 2, 0);
 	for (int i =0 ; i < m; ++i) {
 		int e;
 		cin >> e;
 		++b[e];
 	}

 	int cnt = 0;
 	for (int i = 1; i < 101; ++i) {
		
		int mn = min(a[i], b[i- 1]);
		cnt += mn;
		a[i] -= mn;
		b[i - 1] -= mn;

		mn = min(a[i], b[i]); 
		cnt += mn;
		a[i] -= mn;
		b[i] -= mn;

		mn = min(a[i], b[i + 1]); 
		cnt += mn;
		a[i] -= mn;
		b[i + 1] -= mn;
	
		mn = min(b[i], a[i- 1]);
		cnt += mn;
		b[i] -= mn;
		a[i - 1] -= mn;

		mn = min(b[i], a[i]); 
		cnt += mn;
		b[i] -= mn;
		a[i] -= mn;

		mn = min(b[i], a[i + 1]); 
		cnt += mn;
		b[i] -= mn;
		a[i + 1] -= mn;
		
 	}

 	cout << cnt << '\n';
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
    