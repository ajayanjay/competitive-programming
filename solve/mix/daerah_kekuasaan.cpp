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
#define vll vector<ll>

int maxFour(int a, int b, int c, int d) {
	int mx = a;

	mx = max(mx, b);
	mx = max(mx, c);
	mx = max(mx, d);

	if (mx == a) return 0;
	else if (mx == b) return 1;
	else if (mx == c) return 2;
	else return 3;
}

int get(vector<vi> & a, int l, int r, int u, int d, int sign, int v) {
    if (l > r || u > d) return INT_MIN;
    if (l == r && l == u && l == d) return a[l][l];

    if (sign == 0) {
        for (int i = u; i <= d; ++i)
            v -= a[i][l];
    } else if (sign == 1) {
        for (int i = u; i <= d; ++i)
            v -= a[i][r];
    } else if (sign == 2) {
        for (int i = l; i <= r; ++i) 
            v -= a[u][i];
    } else if (sign == 3) {
        for (int i = l; i <= r; ++i)
            v -= a[d][i];
    }

    int left = get(a, l + 1, r, u, d, 0, v);
    int right = get(a, l, r - 1, u, d, 1, v);
    int up = get(a, l, r, u + 1, d, 2, v);
    int down = get(a, l, r, u, d - 1, 3, v);

    return max(v, max(left, max(right, max(up, down))));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));

    for (auto &x : a) {
    	for (auto &e : x){
    		cin >> e;
    	}
    }

    ll mx = LONG_MIN;
    for (int i = 0; i < n; ++i) {

        vll sm(m, 0);

        for (int j = i; j < n; ++j) {

            for (int l = 0; l < m; ++l) {
                sm[l] += a[j][l];
            }

            ll cur = 0;
            for (int l = 0; l < m; ++l) {
                cur = max(sm[l], cur + sm[l]);
                mx = max(mx, cur);
            }
        }
    }


    cout << mx;
    


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
