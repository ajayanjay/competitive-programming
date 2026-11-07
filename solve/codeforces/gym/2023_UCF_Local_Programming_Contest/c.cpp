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

    vector<vector<char>> mp(n, vector<char>(n, 0));
    int mid = n / 2;

    // start at mp[mid][mid];

    int i = 0;
    int j = 0;

    short d = 0; // [down, right, up, left]

    vector<vector<int>> dir = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    int m = s.size();
    int p = m;
    int cnt = n * n;

    p = min(p, cnt);

    while (p > 0) {

        while (p > 0) {

            // cout << i << ' ' << j << ' ' << cnt << ' ' << p <<  ' ';

            if (cnt > p) {
                --cnt;
                mp[i][j] = '#';
                // cout << '#' << '\n';
            } else { // cnt <= p
                mp[i][j] = s[p - 1];
                // cout << s[p -1 ] << '\n';
                --p;
                --cnt;
            } 

            int next_i = i + dir[d][0];
            int next_j = j + dir[d][1];

            if (next_i >= n || next_i < 0 
                || next_j >= n || next_j < 0 
                || mp[next_i][next_j] != 0 // already used, need to move
                ) {
                break;
            } else {
                i = next_i;
                j = next_j;
            }
        }

        d = (d + 1) % 4;
        i = i + dir[d][0];
        j = j + dir[d][1];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] == '#') continue;
            cout << mp[i][j];
        }
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
    