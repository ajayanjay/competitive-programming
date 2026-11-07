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
#define MAX 1000

int dist[MAX][MAX];

void spread(int x, int y, int d) {
	dist[x][y] = d;

	int nd = d + 1;

	if (x + 1 < MAX && nd < dist[x + 1][y]) {
		spread(x + 1, y, nd);
	}

	if ( y + 1 < MAX && nd < dist[x][y + 1]) {
		spread(x, y + 1, nd);
	}

	if ( x - 1 >= 0 && nd < dist[x - 1][y]) {
		spread(x- 1, y, nd);
	}

	if (y - 1 >= 0 && nd < dist[x][y - 1]) {
		spread(x, y-  1, nd);
	}
}

void solve() {

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			dist[i][j] = INT_MAX;
		}
	}

	deque<pii> p;

    int q;
    cin >> q;
    while(q--) {
    	int t, x, y;
    	cin >> t >> x >> y;
    	--x, --y;

    	if (t == 0) {
    		// spread(x, y, 0);
    		p.pb({x, y});
    		dist[x][y] = 0;
    		while (!p.empty()) {
    			auto [currX, currY] = p.front(); p.pop_front();
    			int d = dist[currX][currY];

    			if (currX + 1 < MAX && d + 1 < dist[currX + 1][currY]) {
    				dist[currX + 1][currY] = d + 1;
    				p.pb({currX + 1, currY});
    			}

    			if (currY + 1 < MAX && d + 1 < dist[currX][currY + 1]) {
    				dist[currX][currY + 1] = d + 1;
    				p.pb({currX, currY + 1});
    			}

    			if (currX - 1 >= 0 && d + 1 < dist[currX - 1][currY]) {
    				dist[currX - 1][currY] = d + 1;
    				p.pb({currX - 1, currY});
    			}

    			if (currY - 1 >= 0 && d + 1 < dist[currX][currY - 1]) {
    				dist[currX][currY - 1] = d + 1;
    				p.pb({currX, currY - 1});
    			}
    		}

    	} else {
    		cout << dist[x][y] << '\n';
    	}
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
    