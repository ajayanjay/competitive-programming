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



vector<string> mp1 = {
    "CBAADDDB",
    "CCDCCADA",
    "BAADACBC",
    "BBCDABBD"
};

vector<string> mp2 = {
    "DADDACBC",
    "DBABCCCD",
    "DCBAADAA",
    "CABBCBBD"
};

pair<char, char> get(char a, char b) {
    a -= 'A';
    b -= 'A';

    char l = mp2[a][b * 2];
    char r = mp2[a][b * 2 + 1];

    l -= 'A';
    r -= 'A';

    char res1 = mp1[l][r * 2];
    char res2 = mp1[l][r * 2 + 1];

    return {res1, res2};
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i += 2) {
        char a = s[i];
        char b = s[i + 1];

        pair<char, char> res = get(a, b);
        cout << res.first << res.second;
    }
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
    