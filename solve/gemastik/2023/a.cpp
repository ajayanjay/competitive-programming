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
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        v[i] = {e, i};
    }

    sort(all(v));
    pii f = v[0];
    pii s = v[n - 1];

    if (f.first == s.first) {
        cout << "SESUAI";
        return;
    }

    int unq = 0;
    int prev = -1;
    vi un;

    int a = -1;
    int aCnt = -1;

    int b = -1;
    int bCnt = -1;

    int c = -1;
    int cCnt = -1;

    for (auto [e, i] : v) {
        // cout << e << ' ' << aCnt << ' ' << bCnt << ' ' << cCnt << '\n';
        if (prev == -1) {
            prev = e;
            unq++;

            a = e;
            aCnt = 1;
        } else {
            if (e == a) {
                aCnt++;
            } else if (e == b) {
                bCnt++;
            } else if (e == c) {
                cCnt++;
            }

            if (prev != e) {
                ++unq;

                if (prev == a) {
                    b = e;
                    bCnt = 1;
                } else if (prev == b) {
                    c = e;
                    cCnt = 1;
                }

                prev = e;

                if (unq > 3) {
                    cout << "TIDAK SESUAI";
                    return;
                }
            }
        }
    }

    // aa b c | a b cc cant
    // a bb c can
    // aa b cc cant
    if (unq == 1) { // impossible to reach
        cout << "SESUAI";
        return;
    } else if (unq == 2) {
        if (aCnt > 1 || bCnt > 1) {
            cout << "TIDAK SESUAI";
            return;
        }

        if (b % 2 != a % 2) {
            cout << "TIDAK SESUAI";
            return;
        }

        int df = (b - a) / 2;
        cout << df << ' ' << (s.second + 1) << ' ' << (f.second + 1);
        return;
    } 

    // unq = 3.

    if (aCnt > 1 || cCnt > 1) {
        cout << "TIDAK SESUAI";
        return;
    }

    if (a % 2 != c % 2) {
        cout << "TIDAK SESUAI";
        return;
    }

    int dfa = (b - a);
    int dfc = (c - b);

    if (dfa != dfc) {
        cout << "TIDAK SESUAI";
        return;
    }

    cout << dfa << ' ' << (s.second + 1) << ' ' << (f.second + 1);

    

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
    