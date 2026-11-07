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

int a, b;

bool get(vi &d, vi &t, int i) {

    int n = 6;
    if (i == n) {

        int res = 1;
        bool h = false;
        for (int x = 0; x < 6; ++x) {
            int e = d[x];
            if (!h && e != 0) h = true;

            if (h)
                res *= e;
        }

        return res != 0 && res % b == 0;
    }

    for (int j = t[i]; j <= 9; ++j) {
        d[i] = j;
        if (get(d, t, i + 1)) return true;
    }

    t[i] = 0;

    return false;
}

void solve() {
    cin >> a >> b;

    vi t(6, 0);
    int x = 100000;
    int i = 0;
    int a1 = a + 1;
    while (a1 > 0) {
        t[i] = a1 / x;
        a1 %= x;
        x /= 10;
        ++i;
    }

    vi d(6, 0);
    bool e = get(d, t, 0);

    if (!e) {

        vector<pii> nums;
        int f = 9;
        while (b > 1 && f >= 2) {
            int cnt = 0;
            while (b > 1 && b % f == 0) {
                b /= f;
                ++cnt;
            }
            if (cnt > 0) nums.pb({f, cnt});

            --f;
        }

        if (b > 1) {
            cout << -1;
            return;
        }

        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            auto [e, cnt] = nums[i];
            while (cnt--) {
                cout << e;
            }
        }
        return;
    }

    bool h = false;
    for (int i = 0; i < 6; ++i) {
        int e = d[i];
        if (!h && e != 0) h = true;

        if (h) {
            cout << e;
        }
    }
}

void solve2() {
    string a;
    cin >> a;
    int b;
    cin >> b;

    vector<pii> nums;
    int f = 9;
    while (b > 1 && f >= 2) {
        int cnt = 0;
        while (b > 1 && b % f == 0) {
            b /= f;
            ++cnt;
        }
        if (cnt > 0) nums.pb({f, cnt});

        --f;
    }

    if (b > 1) {
        cout << -1;
        return;
    }

    int n = nums.size();
    string s;
    for (int i = n - 1; i >= 0; --i) {
        auto [e, cnt] = nums[i];
        while (cnt--) {
            s.push_back((char) (e + 'A'));
        }
    }

    if (s.size() > 5 || s.size() > a.size()) {
        cout << s;
        return;
    }

    vi t(6, 0);
    for (int i = 0; i < a.size() ;++i) {
        t[6 - i] = a[a.size() - i];
    }

    t[5]++;




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
    