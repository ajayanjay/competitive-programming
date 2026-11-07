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
    ll n, d, s;
    cin >> n >> d >> s;

    ll t_n = n / s, t_d = d / s;

    // 64 35 3 -> 21 11 1
    // 1 -> 10 -> 20 <= 21
    // 1 -> 12 -> 24 > 21
    // 1 -> 11 -> 22 > 21

    // 2 x 11 -> 22 -> min (22, 21) -> 21
    // Y = 21
    // Y not even -> find X such that Y % X == 0 and Y - (Y / X) <= D 

    ll y = min(2 * t_d, t_n);

    if (y % 2 == 0) {
    	cout << y * s;
    } else {
    	bool f = false;

        if (y > 1)
    	for (ll x = 3; x * x <= y; x += 2) {
    		if (y % x == 0) {
                cout << (y - (y / x)) << ' ';
                if ((y - (y / x)) <= d) {
                    f = true;
                    break;
                }
            }
    	}

    	if (f) {
    		cout << y * s;
    	} else {
    		cout << (y - 1) * s;
    	}

    }


    // 20 x 3 = 60
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
