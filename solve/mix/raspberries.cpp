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
    int n, k, e;
    cin >> n >> k;

    int mn = INT_MAX;
    if (k == 4) {
        int min_op = 2;
        int evens = 0;
        int close = 0;
        for (int i = 0; i < n; ++i) {
            cin >> e;

            if (e % 4 == 0) mn = 0;
            else if ((e + 1) % 4 == 0) ++close;
            else if (e % 2 == 0) ++evens;
        }  
        if (mn != 0) {
            if (evens >= 2) mn = 0;
            else if (evens > 0 || close > 0) mn = 1;
            else mn = 2;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> e;

            if (e % k == 0) mn = 0;
            else mn = min(mn, k - (e % k));
        }
    }
    cout << mn << '\n';
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
