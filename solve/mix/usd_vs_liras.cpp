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

struct _t {
    int dollar, rate;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n), b(n);
    for (auto & e : a)
        cin >> e;
    for (auto & e : b)
        cin >> e;

    vector<_t> v(n);
    for (int i = 0 ;i   <n ; ++i)
        v[i] = {a[i], b[i]};

    sort(all(v), [&](const _t & a, const _t & b) {
        return a.rate > b.rate;
    });

    
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
    