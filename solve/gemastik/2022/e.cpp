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

    vi a(n);
    for (auto &e : a) {
        cin >> e;
    }

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    int prevL = -1;
    int prevR = -1;
    bool f = true;
    for (auto e : a) {
        if (prevL == -1) {
            prevL = e;
            prevR = e;
            continue;
        } else {
            if (prevR + 1 == e) {
                prevR = e;
            } else {
                if (prevL == prevR) {
                    if (f) f = false;
                    else {
                        cout << ",";
                    }
                    cout << prevL;
                } else {
                    if (f) f = false;
                    else {
                        cout << ",";
                    }
                    cout << prevL << '-' << prevR;
                }

                prevL = e;
                prevR = e;
            }
        }
    }

    if (prevL == prevR) {
        if (f) f = false;
        else {
            cout << ",";
        }
        cout << prevL;
    } else {
        if (f) f = false;
        else {
            cout << ",";
        }
        cout << prevL << '-' << prevR;
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
    