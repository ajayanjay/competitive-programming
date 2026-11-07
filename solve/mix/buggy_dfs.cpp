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

ll bdfs(vector<vector<int>> &g) {

	for (auto l : g) sort(all(l));

	deque<int> s;
	vector<bool> flag(g.size());
	ll cnt = 0;

	s.push_front(0);

	while (!s.empty()) {
		int u = s.front();
		s.pop_front();

		flag[u] = true;

		for (auto v : g[u]) {
			++cnt;
			if (!flag[v])
				s.push_front(v);
		}
	}

	return cnt;
}

void solve() {
    int k;
    cin >> k;

    // largest vertex will always processed once
    // 1 ... n
    // 1 ... 1 
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
    