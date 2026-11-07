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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

struct _t {
	pair<int, int> pos; ll dist;

	bool operator>(const _t& other) const {
        return dist > other.dist;
    }
    bool operator<(const _t& other) const {
        return dist < other.dist;
    }
};

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

vector<vll> bfs(vector<string> &h, int r, int c, int x) {
	vector<vll> d(r, vll(c, LLONG_MAX));
	priority_queue<_t, vector<_t>, greater<_t>> q;
	vector<vector<bool>> vis(r, vector<bool>(c, false));

	q.push({{0,0}, 0});
	d[0][0] = 0;

	auto yes = [&](int _r, int _c) {
        return _r >= 0 && _r < r && _c >= 0 && _c < c;
    };
	while (!q.empty()) {
		_t _ = q.top(); q.pop();
		ll _r = _.pos.first, _c = _.pos.second, dist = _.dist;

		if(vis[_r][_c]) continue;
		vis[_r][_c] = true;

		for (int k = 0; k < 4; ++k) {
			int nr = _r + dr[k], nc = _c + dc[k];

			if (!yes(nr, nc)) continue;

			ll w = binpow(h[_r][_c] - h[nr][nc], x);
			if (d[nr][nc] > dist + w) {
				d[nr][nc] = dist + w;
				q.push({{nr, nc}, d[nr][nc]});
			}
		}
	}

	return d;
}

void solve() {
    int r, c, x;
    cin >> r >> c >> x;

    vector<string> h(r);
    for (int i =0 ; i  < r; ++i)
    	cin >> h[i];

    bool zero_cycle = false;
    for (int i = 0; i < r - 1; ++i) {
    	for (int j = 0; j < c - 1; ++j) {

    		int e1 = h[i][j] - '0';
    		int e2 = h[i][j + 1] - '0';
    		int e3 = h[i + 1][j] - '0';
    		int e4 = h[i + 1][j + 1] - '0';

    		int s1 = binpow((e1 - e2), x);
    		int s2 = binpow((e2 - e3), x);
    		int s3 = binpow((e3 - e4), x);
    		int s4 = binpow((e4 - e1), x);

    		if ((s1 + s2 + s3 + s4) < 0) {
    			zero_cycle = true;
    			break;
    		}
    	}

    	if (zero_cycle) break;
    }

    vector<vll> d = bfs(h, r, c, x);

    int q;
    cin >> q;
    while (q--) {
    	int Rs, Cs, Rf, Cf;
    	cin >> Rs >> Cs >> Rf >> Cf;

    	if (zero_cycle) {
    		cout << "INVALID\n";
    		continue;
    	}

    	cout << d[Rf - 1][Cf - 1] - d[Rs - 1][Cs - 1] << '\n';
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
    