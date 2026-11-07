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

#define MAX_N 1e5 + 1

void solve() {
    int n;
    cin >> n;

    vector<ull> a(MAX_N, 0);
    for (int i = 0; i < n; ++i) {
    	int e;
    	cin >> e;
    	a[e] += e;
    }

    for (int i = 2; i < MAX_N; ++i) {
    	a[i] = max(a[i - 1], a[i - 2] + a[i]);
    }

    cout << a[MAX_N - 1];
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
