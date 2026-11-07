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

const int mod = 1000000007;

void solve() {
    int n; cin >> n;

    // since there are only 2 layers (2 * N)
    /*
        we only need to care on the first floor only, find all possible combination
        and then for each possible combination times with the TOTAL possible combination.
        essentially this means that the answer is
        (all possible combination)^2. (indeed, if the problem generalizes to K layers, we can expand this to ^K)

        now to find all possible combination of N
        
        N -> needed N / 2 rectangles.
        
        1 -> 1 -> 1
        2 -> 2 -> 4
        3 -> 3 -> 9
        4 -> 5 -> 25
        5 -> 8 -> 64
        6 -> 13 -> 169

    */



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
    