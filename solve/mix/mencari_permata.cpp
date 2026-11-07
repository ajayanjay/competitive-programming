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
#define MOD 1000000007



void solve() {
    int n, m;
    cin >> n >> m;

    if (n <= 1 || m <= 1) {
    	cout << 1;
    	return;
    }
    // 3 -> 7
    // 3C1 + 3C2 + 3C3
    // 3 + 3 + 1
    // A B C AB AC BC ABC
    // sum of nC{1..n}
    // many ways to pick n items.
    // 2^n - 1

    // 4 -> 15
    // A B C D AB AC AD BC BD CD ABC ABD BCD ABCD

    /*
	
    */

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
    