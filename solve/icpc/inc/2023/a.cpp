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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n), t(n);
    for (int i = 0 ; i < n; ++i) {
    	cin >> s[i] >> t[i];
    }

    // n teams
    // the top M teams (less than M are eligible), greater than M needs golden ticket
    // given k tickets

    unordered_set<string> mp;
    vector<string> ans;

    for (int i = 0; i < m; ++i) {
    	string institute = t[i];
    	string team = s[i];

    	mp.insert(institute);
    }

    for (int i = m; i < n; ++i) {
    	string institute = t[i];
    	string team = s[i];

    	if (mp.find(institute) == mp.end()) {
    		mp.insert(institute);
    		ans.pb(team);
    	}

    	if (ans.size() >= k) break;
    }

    cout << ans.size() << '\n';
    for (auto & str : ans) {
    	cout << str << '\n';
    }
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
    