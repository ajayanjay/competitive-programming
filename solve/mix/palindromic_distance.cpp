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

bool checkPal(string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}


int largest_num(const string &str1, const string &str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int max_len = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = max(max_len, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return max_len;
}

void solve() {
    string s;

    cin >> s;
    
    int n = s.size();

    // all substrings of length 1 are palindromes
    int maxLen = 1, start = 0;

    // nested loop to mark start and end index
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          
            // check if the current substring is 
            // a palindrome
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }


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
    