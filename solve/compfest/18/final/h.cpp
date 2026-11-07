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

bool isPalindrome(string s) {
    int l = 0;
    int n = s.size();
    int r = n - 1;

    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }

    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (isPalindrome(s)) {
        cout << 0;
        return;
    }

    int l, r;
    if (n % 2 == 0) {
        r = n / 2;
        l = r - 1;
    } else {
        r = (n / 2) + 1;
        l = (n / 2) - 1;
    }

    int debt = 0;
    int ans = 0;
    while (l >= 0 && r < n) {
        char left = (s[l] + debt - 'A') % 26 + 'A';
        char right = s[r];

        if (left != right) {
            // get diff
            int diff;
            right -= 'A';
            left -= 'A';
            if (left < right) {
                diff = right - left;
            } else { // left > right, go around
                diff = (26 - left) + right;
            }

            debt += diff;
            ++ans;

            // cout << l << ' ' << diff << ' ' << debt << '\n';
        }

        --l;
        ++r;
    }

    cout << ans;
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
