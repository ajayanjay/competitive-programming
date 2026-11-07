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
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int r[4] = {a, b, c, d};
	int res = 0;

	int prevCarry = -1;
	int carry = 0;

	for (int i = 0; i < 4; ++i) {
		int curr = r[i];

		if (curr == 0) continue;

		if (carry > 0 && prevCarry != -1 && 
			!((prevCarry == 0 && i == 1) || (prevCarry == 2 && i == 3))
			) {
			int mn = min(carry, curr);
			curr -= mn;
			carry -= mn;
			prevCarry = i;
		}

		if (curr > 0) {
			res += (curr / 3);
			int rem = curr % 3;
			if (rem == 0) {
				carry = 0;
				prevCarry = i;
			} else {
				++res;
				carry = 3 - rem;
				prevCarry = i;
			}
		}
	}
	cout << res;
}

// this solves eating a b c d
// a and b cannot be eaten on the same day
// c and d cannot be eaten on the same day
// priority: a -> b -> c -> d, but not in a 'finish a first, then eat b' fashion
// but in 'a has to reach 0 first. then b then c and so on'.
// fuck this problme statement, genuinely shit.
void solve2() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// a lampia daging
	// b lampia ayam
	// c lumpia udang
	// d lumpia ikan

	// 1 hari 3 buah
	// a b gaboleh sama
	// c d gaboleh

	// priority: a -> b -> c -> d
	// does priority eve nmatters?
	// yes..

	// eat a until finish
	// took a / 3 days
	// but on the last piece, can be mixed with either c or d
	// mix with c.

	// (a + b -= a % 3) / 3


	int res = a / 3;
	a %= 3;

	if (b != 0) {
		res += (b / 3) + (b % 3 == 0 ? -1 : 0);
		if (b % 3 != 0) b %= 3;
		else b = 3;
	}

	if (c != 0) {
		res += (c / 3) + (c % 3 == 0 ? -1 : 0);
		if (c % 3 != 0) c %= 3;
		else c = 3;
	}

	if (d != 0) {
		res += (d / 3) + (d % 3 == 0 ? -1 : 0);
		if (d % 3 != 0) d %= 3;
		else d = 3;
	}

	// a b c d is <= 3.

	// find good combination
	// good combination allows b and c to be eaten at the same day

	if (b == 0) { // if b is already 0
		if (c == 0) { // a 0 0 d
			int x = a + d;
			res += x / 3 + (x % 3 == 0 ? 0 : 1);
		} else { // a 0 c d
			int x = a + c;
			res += x / 3 + (x % 3 == 0 ? 0 : 1);
			res += (d != 0); // 0 0 0 0 | 0 0 0 d
		}

		cout << res;
		return;
	}

	// b and c cannot be eaten on the same day if b + c > 3

	if (c == 0) {
		if (b + d > 3) {
			if (a != 0) { // a b 0 d
				// a still has the chance to make miracle.
				int rem = 3 - a; 
				int mn = min(rem, d);
				d -= mn;
				a = 0;
				if (d == 0) d = 1;
				++res;
			} else { // 0 b 0 d
				// just.. do it normally. i dont fucking care anymore.
				int x = b + d;
				res += x / 3 + (x % 3 == 0 ? 0 : 1);

				cout << res;
				return;
			}
		} 

		// a b 0 d
		if (b + d <= 3) { // if b + d <= 3, we can just eat a and d together
			
			if (b != 0 || d != 0) {
				++res;
			}
			if (a != 0) {
				++res;
			}
			cout << res;
			return;
		} else { // 0 b 0 d
			int x = b + d;
			res += x / 3 + (x % 3 == 0 ? 0 : 1);
			cout << res;
			return;
		}
	} else { // a b c d
		if (b + c > 3) {
			if (a != 0) { // a b c d
				// a still has the chance to make miracle.
				int rem = 3 - a; 
				int mn = min(rem, c);
				c -= mn;
				a = 0;
				if (c == 0) c = 1;
				++res;
			} else { // 0 b c d
				// just.. do it normally. i dont fucking care anymore.
				if (b != 0) ++res;
				if (c != 0) ++res;
				if (d != 0) ++res;

				cout << res;
				return;
			}
		} 

		if (b + c <= 3) { // if b + c <= 3, we can just eat a and d together
			// a b c d
			if (b != 0 || c != 0) {
				++res;
			}
			if (a != 0) {
				++res;
			}

			if (d != 0) {
				++res;
			}

			cout << res;
			return;
		} else { // if this is still not fucking enough
			// 0 b c d
			// just do it normally atp..

			if (b != 0) ++res;
			if (c != 0) ++res;
			if (d != 0) ++ res;
			cout << res;
			return;
		}
	}



}

signed main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
    	// for (int a = 0; a <= 3; ++a) {
    	// 	for (int b = 0; b <= 3; ++b) {
    	// 		for (int c = 0; c <= 3; ++c) {
    	// 			for (int d = 0; d <= 3; ++d) {
    	// 				cout << a << " " << b << ' ' << c << ' ' << d << '\n';
    	// 				solve(a, b, c, d);
    	// 				cout << '\n';
    	// 			}
    	// 		}
    	// 	}
    	// }

    	solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    