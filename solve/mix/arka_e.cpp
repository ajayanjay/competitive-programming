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
#define ull unsigned ll

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ull total_0 = 0, total_1 = 0;
    for (auto c : s) {
    	if (c == '0') ++total_0;
    	else ++total_1;
    }

    ull max_0 = total_0 * k;
    ull max_1 = total_1 * k;

    int l_0 = 0, r_0 = total_0;
    int l_1 = 0, r_1 = total_1;

    int diff = total_0 - total_1;
    bool diff_positive = (diff > 0);
    bool diff_negative = (diff < 0);
    bool diff_eq = (diff == 0);	

    int count = 0;
    for (auto c : s) {

    	if (c == '0') {
    		--r_0, ++l_0;
    	} else {
    		--r_1, ++l_1;
    	}    	

    	ll l_diff = l_0 - l_1;
    	ll r_diff = (max_0 - l_0) - (max_1 - l_1);

    	bool l_positive = (l_diff > 0);
    	bool l_negative = (l_diff < 0);
    	bool l_eq = (l_diff == 0);

    	bool r_positive = (r_diff > 0);
    	bool r_negative = (r_diff < 0);
    	bool r_eq = (r_diff == 0);

    	if (diff_eq) {
    		if (r_negative && l_negative) continue;
    		if (r_positive && l_positive) continue;
    		if (r_eq || l_eq) continue;

    		if (r_positive && l_negative) {count += k; continue;}
    		if (r_negative && l_positive) {count += k; continue;}
    	}

    	if (r_positive && l_negative && (diff_negative || diff_eq)) {
    		count += k;
    		continue;
    	}

    	if (r_negative && l_positive && (diff_positive || diff_eq)) {
    		count += k;
    		continue;
    	}

    	// r_positive && l_negative && diff_positive -> has 3 possible condition
    	// r_negative && l_positive && diff_negative -> has 3 possible condition

		l_diff = abs(l_diff);
		r_diff = abs(r_diff);

		ll t_diff = abs(diff);

		ll mn = min(l_diff, r_diff);
		ll mx = max(l_diff, r_diff);

		ll k_diff = k;

		ll amt = (mn / t_diff) + (mn % t_diff == 0 ? 0 : 1);
		amt = min(k_diff, amt);

		mn -= amt * t_diff;
		mx -= amt * t_diff;
		count += amt;

		k_diff -= amt;
		
		if (k_diff == 0) continue;

		if (mn == 0) mn -= t_diff, mx -= t_diff, k_diff--;
		// mn should be negative here.

		if (k_diff == 0) continue;

		if (mx > 0) {
			amt = (mx / t_diff) + (mx % t_diff == 0 ? 0 : 1);
			amt = min(k_diff, amt);

			mx -= amt * t_diff;
			mn -= amt * t_diff;
			count += amt;

			k_diff -= amt;
		}

		if (k_diff == 0) continue;
		if (mx == 0) mn -= t_diff, mx -= t_diff, k_diff--;
		// mx should also be negative here.

		if (k_diff == 0) continue;

		count += k_diff;

	}

    cout << count; 
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
    