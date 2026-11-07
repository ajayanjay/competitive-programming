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

void fill(vector<vi> &ans, int h, int w) {
    int val = 1, cnt = 0;

    int i = 0, j = 0;

    pii dir = {-1, 0}; // down
    int sz = 1;
    bool d1 = false;
    bool d2 = false;
    bool d4 = false;
    bool d3 = false;
    while (i < h && j < w) {
        
        ans[i][j] = val;
        ++cnt;

        if (cnt == val) {
            cnt = 0;
            ++val;
        }

        if (d1) { // hit upper wall
            d1 = false;
            dir.first = 1;
            dir.second = 0;
        }

        else if (d2) { // hit left wall
            d2 = false;
            dir.first = 0;
            dir.second = 1;
        }

        else if (d3) { // hit bottom wall
            d3 = false;
            dir.first = -1;
            dir.second = 0;
        }

        else if (d4) { // hit right wall, unlikely
            d4 = false;
            dir.first = 0;
            dir.second = -1;
        }

        else if (i == j) {
            if (i % 2 == 0) { // even
                dir.first = 1;
                dir.second = 0;
            } else {
                dir.first = 0;
                dir.second = -1;
            }
        }

        else if (i + dir.first < 0) { // if hit top wall
            dir.second = 1;
            dir.first = 0;
            d1 = true;
        }

        else if (i + dir.first >= h) { // hit bottom wall
            dir.second = 1; // go right
            dir.first = 0;
            d3 = true;
        }

        else if (j + dir.second < 0) { // hit left most wall
            dir.first = 1; // go down
            dir.second = 0;
            d2 = true;
        }

        else if (j + dir.second >= w) { // hit right most wall, unlikely
            dir.first = 1;
            dir.second = 0;
            d4 = true;
        }

        i += dir.first;
        j += dir.second;
    }
}

bool solve() {
    int n;
    cin >> n;

    // sum i = n * (n + 1) / 2

    int totalE = n * (n + 1) / 2;

    int h;
    for (h = 1; h <= 2026; ++h) {
        if (totalE % h == 0 && totalE / h <= 2026) break;
    }
    int w = totalE / h;

    if (h > 2026 || w > 2026) {
        return false;
    }

    vector<vi> ans(h, vi(w, 0));
    fill(ans, h, w);

    vi assurance(n + 1, 0);
    for (auto & x : ans) {
        for (auto & e : x) {
            assurance[e]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (assurance[i] != i) {
            return false;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int e = ans[i][j];

            if (i - 1 >= 0 && abs(e - ans[i - 1][j]) > 2) {
                return false;
            }

            if (j - 1 >= 0 && abs(e - ans[i][j - 1]) > 2) {
                return false;
            }

            if (i + 1 < h && abs(e - ans[i + 1][j]) > 2) {
                return false;
            }

            if (j + 1 < w && abs(e - ans[i][j + 1]) > 2) {
                return false;
            }
        }
    }

    cout << h << ' ' << w << '\n';
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return true;
}

signed main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();

        if (!solve()) cout << -1;
    }
    return 0;
}
    