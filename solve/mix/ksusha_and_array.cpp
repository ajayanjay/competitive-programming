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
    vi a(n);
    set<int> s;

    int res;

    bool first = true;
    for (auto & e : a){
    	cin >> e;
    	s.insert(e);
    	if (first) {
    		res = e;
    		first = false;
    	} else {
    		res = gcd(res, e);
    	}
    }

    int ans = -1;
    if (s.find(res) != end(s)) ans = res;
    for (auto e : s) {
    	if (e * e > res) break;

    	if (res % e == 0) {
    		ans = e;
    		break;
    	}
    }

    cout << ans;
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
    