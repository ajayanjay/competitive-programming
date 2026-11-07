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

int maxSubarrayLength(vector<int>& nums, int k) {

    int n = nums.size();

    if (k >= n) {
        return k;
    }

    unordered_map<int, int> mp;

    int l = 0, r = 0;

    for (r = 0; r < n; ++r) {
        int e = nums[r];

        if (mp[e] == k) {
            --r;
            break;
        }

        mp[e]++;
    }

    if (r == n) r = n - 1;

    int maxDist = (r - l + 1);

    // since we want to maximize the length, the l shouldn't be truncated.

    while (r < n - 1) {

    	// truncate l until we find element next to R.

        // cout << l << ' ' << r << '\n';

    	int c = nums[r + 1];
    	for (; l <= r;) {
    		int e = nums[l];
            ++l;

            --mp[e];
            if (e == c) break;
    	}

    	// expand r until exit.
        // forward checkup.

    	for (; r < n - 1;) {
    		int e = nums[r + 1];

    		if (mp[e] == k) {
                break;
            }

            mp[e]++;
            ++r;
    	}

    	int dist = r - l + 1;
    	if (maxDist < dist) {
    		maxDist = dist;
    	}
    }

    // cout << l << ' ' << r << '\n';

    return maxDist;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (auto &e: a) cin >> e;

    cout << maxSubarrayLength(a, k);

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
    