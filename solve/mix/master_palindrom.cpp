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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    int l = 0, r = n - 1;
    while (l <= r) {

    	if (l == r) {
    		++res;
    		break;
    	}

    	// l != r, both same char, 
    	if (s[l] == s[r]) {
    		res += 2;
    		++l, --r;
    		continue;
    	}

    	// save l
    	int tempL = l;
    	int tempR = r;

    	// left go right until it meets first matching char
    	while (l < r && s[l] != s[r]) ++l;
    	if (l >= r) {
    		++res;
    		break;
    	}

    	// save state here.
    	int tempL2 = l;

    	// both left and right is now at the same char
    	// both walks back to make sure they are the same char
    	while (l >= tempL && s[l] == s[r]) {
    		--l, --r;
    	}

    	++l, ++r; // make sure l and r points to the same char

    	// if tempL != l, we try to find from r.
    	if (tempL != l) {
    		l = tempL;
    		r = tempR;

    		while (l < r && s[l] != s[r]) --r;
    		if (l >= r) {
    			++res; 
    			break;
    		}

    		int tempR2 = r;

    		while (r <= tempR && s[l] == s[r]) {
    			++l, ++r;
    		}

    		--l, --r;

    		if (tempR != r) {
    			++res;
    			break;
    		}

    		res += 2;
 			r = tempR2;
 			++l, --r;
 			continue;
    	}

    	// if tempL == l, then we can continue iterating.
    	res += 2;
    	l = tempL2; // put l at saved state.
    	++l, --r;
    }

    cout << res;
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
    