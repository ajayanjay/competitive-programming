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

vector<string> parse(string s) {

    int i = 0, j = 0;

    vector<string> res;

    while (j < s.size()) {
        while (j < s.size() && s[j] != '.') {
            ++j;
        }

        res.push_back(s.substr(i, j - i));
        i = j = j + 1;

    }
    return res;
}

void solve() {
    string s;
    cin >> s;

    if (s[s.size() - 1] == '.' || s[0] == '.') {
        cout << "NO";
        return;
    }

    vector<string> parsed = parse(s);
    if (parsed.size() == 1) {
        cout << "NO";
        return;
    }

    vector<string> res;

    for (int i = 0; i < parsed.size(); ++i) {
        string e = parsed[i];

        if (i == 0 || i == parsed.size() - 1) {
            res.push_back(e);
            continue;
        }

        if (e.size() > 11 || e.size() < 2) {
            cout << "NO";
            return;
        }

        int n;
        if (e.size() < 4) {
            n = 1;
        } else {
            n = 3;
        }

        string s1 = e.substr(0, n);
        string s2 = e.substr(n, e.size() - 1);

        res.push_back(s1);
        res.push_back(s2);
    }

    string f = res[0], l = res[res.size() - 1];
    if (f.size() == 0 || f.size() > 8 || l.size() > 3 || l.size() == 0) {
        cout << "NO";
        return;
    }

    cout << "YES" << '\n';
    for (int i = 0 ; i < res.size() - 1; i += 2) {
        cout << res[i] << '.' << res[i + 1] << '\n';
    }

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
    