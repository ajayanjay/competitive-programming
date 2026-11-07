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
    
    ll n, k;
    cin >> n >> k;

    // 1 -> 1
    // 2 -> 2
    // 3 -> 2
    // 4 -> 3
    // 5 -> 3
    // .. 8 -> 4

    ll res = floor(log2(k)) + 1;

    if (res > n) res = n;

    cout << res << '\n';
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
    