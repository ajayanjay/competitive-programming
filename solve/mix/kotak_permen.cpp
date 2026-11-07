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
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<int> nums(26, 0);
    for (char c : s) {
        ++nums[c - 'A'];
    }
    
    int res = 0;

    sort(all(nums));
    n = nums.size();
    
    int start = 0;
    while (start < n && nums[start] == 0) ++start;

    
    
}

signed main() {
    // fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    