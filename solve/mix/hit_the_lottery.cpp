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

const int lib[5] = {100, 20, 10, 5, 1};

void solve() {
    int n;
    cin >> n;

    int res = 0;

    for (int i = 0; i < 5 ; ++i) {
    	res += n / lib[i];
    	n %= lib[i];
    }

    cout << res;
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
    