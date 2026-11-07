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
    ll n, r, k;
    cin >> n >> r >> k;

    if (n == 1) {
    	unsigned ll temp = r * k;
    	cout << temp << '\n';
    	return;
    }

    ll l = k;

    unsigned ll res = 0;

    // create a block
    /*
	| kiri | --- the rest --- |
	| --- the rest --- | kanan |
    */

    // n = 3, r = 4, k = 7;

    ll divr = r / n; // 1 -> 1 1 1
    ll right_r = (r - divr * n); // 4 - 3 = 1 -> 1 1 2 (terdapat 1 2s)
    ll left_r = n - right_r; // 3 - 1 = 2 -> 1 1 2 (terdapat 2 1s)

    ll divl = l / n; // 7 / 3 -> 2 2 2
    ll left_l = (l - divl * n); // 7 - 6 = 1 -> 3 2 2 (terdapat 1 3s)
    ll right_l = n - left_l; // 3 - 1 = 2 -> 3 2 2 (terdapat 2 2s)

    if (left_l < left_r) {
    	ll first = left_l;
    	ll second = left_r - left_l;
    	ll third = right_r;

    	res += first * (divl + 1) * divr;
    	res += second * divl * divr;
    	res += third * divl * (divr + 1);
    } else if (left_l > left_r) {
    	ll first = left_r;
    	ll second = left_l - left_r;
    	ll third = right_l;

    	res += first * (divl + 1) * divr;
    	res += second * (divl + 1) * (divr + 1);
    	res += third * divl * (divr + 1);
    } else {
    	res += left_l * (divl + 1) * divr;
    	res += right_l * divl * (divr + 1);
    }

    // for (ll i = 0; i < n; ++i) {
    // 	ll a, b;
    // 	if (i < left_l) {
    // 		a = divl + 1;
    // 	} else {
    // 		a = divl;
    // 	}

    // 	if (i < left_r) {
    // 		b = divr;
    // 	} else {
    // 		b = divr + 1;
    // 	}

    // 	res += a * b;
    // }

    // cout << right_l << ' ' << right_r << ' ' << left_l << ' ' << left_r << '\n';
    cout << res << '\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    