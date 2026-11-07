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

#define min(a, b) ((a) < (b) ? (a) : (b)) 

void solve() {
    int n;

    cin >> n;
    vi a(n);
    for (auto &e : a) {
    	cin >> e;
    }

    if (n <= 1) {
    	cout << 0 << '\n';
    	return;
    }



    // i -> j: a_i * abs(i - j)
    ll sm = 0;
    ll cur = a[0];
    ll curIdx = 1;

    for (int i = 1; i < n - 1; ++i) {
        if (cur > a[i]) {
            sm += cur * abs(curIdx - (i + 1));
            curIdx = i + 1;
            cur = a[i];
        }
    }

    sm += cur * abs(curIdx - (n));

    cout << sm;



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
    