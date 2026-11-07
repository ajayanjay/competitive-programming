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
    int m, s;
    cin >> m >> s;

    if (m == 1 && s == 0) {
    	cout << 0 << ' ' << 0;
    	return;
    }

    vi res(m, 0);

    int f = 0, l = res.size() - 1;

    while (f < res.size() && s > 0) {
    	if (res[f] == 9) ++f;
    	if (f >= res.size()) break;
    	res[f]++, s--;
    }

    if (res[0] == 0 || s > 0) {
    	cout << -1 << ' ' << -1;
    	return;
    }

    if (res[l] == 0) {

    	if (f == 0 && res[f] == 1) {
    		for (auto e : res)
    			cout << e;
    		cout << ' ';
    		for (auto e : res)
    			cout << e;
    		return;
    	}

    	else {
    		res[f]--, res[l]++;
    		for (int i = l; i >= 0; --i)
    			cout << res[i];
    		res[f]++, res[l]--;
    	}

    } else {
    	for (int i = l; i >= 0; --i)
    		cout << res[i];
    }

    cout << ' ';

    for (auto e : res)
    	cout << e;
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
