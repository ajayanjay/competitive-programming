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

const int N = 1 << 18;
int a[N], mn[N];

void solve() {
    int q, k;
    cin >> q >> k;

    multiset<int> ms;

    for (int i = 0; i < N; ++i) {
    	int curr = 0;

    	for (int j = 29; j >= 0; --j)
    		if (i >> j & 1) 
    			if (curr + (1 << j) <= k)
    				curr += 1 << j;

    	mn[i] = i - curr;
    	ms.emplace(mn[i]);
    }

    while (q--) {
    	int x;
    	cin >> x;

    	if (x < N) {
    		a[x] ^= 1;
    		if (a[x]) 
    			ms.erase(ms.find(mn[x]));
    		else
    			ms.emplace(mn[x]);
    	}

    	cout << *ms.begin() << '\n';
    }
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
    