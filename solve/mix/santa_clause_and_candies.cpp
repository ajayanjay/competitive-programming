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

    vi res;

    int i = 1;
    while ((n - i) >= 0) {
    	res.push_back(i);
    	n -= i;
    	++i;
    }

    if (res.size() == 0) {
    	res.push_back(1);
    } else {
    	res[res.size() - 1] += n;
    }

    cout << res.size() << '\n';
    for (auto e : res)
    	cout << e << ' ';


    // 1 1 1 1 1 1 1 1 1 1 1 1 1
    // 2 1 1 1 1 1 1 1 1 1 1 1
    // 2 3 1 1 1 1 1 1 1 1
    // 2 3 4 1 1 1 1
    // 2 3 5 1 1 1
    // 3 4 5 1

    // 7
    // 4 3
    // 4 2 1

    // 13
    // 7 6
    // 7 3 3
    // 7 3 2 1

    // 4
    // 3 1

    // 3
    // 2 1


    // 12
    // 7 5
    // 7 3 2
    // 6 3 2 1

    // 1 1 1 1 1 1 1 1 1 1 1 1
    // 2 1 1 1 1 1 1 1 1 1 1
    // 2 3 1 1 1 1 1 1 1
    // 2 3 4 1 1 1
    // 2 4 5 1
   	
   	// 1 1 1 1 1 1 1 1 1
   	// 2 1 1 1 1 1 1 1
   	// 2 3 1 1 1 1
   	// 2 3 4
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
    