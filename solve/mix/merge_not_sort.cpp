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

vi merge(vi a, vi b) {
    vi c;
    int i = 0, j = 0;
    
    int n = a.size();

    while (i < n && j < n) {
        if (a[i] < b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }

    while (i < n) c.push_back(a[i++]);
    while (j < n) c.push_back(b[j++]);

    return c;
}

void solve() {
    int n;
    cin >> n;

    int c_size = n * 2;
    vi c(c_size);

    for (auto &e : c)
        cin >> e;

    vi a, b;

    for (int i = 0; i < c_size;) {
        if (a.size() == n) {
            while (i < c_size) b.push_back(c[i++]);
            break;
        }

        int first_e = c[i];
        int j = i + 1;
        while (j < c_size && first_e > c[j]) ++j;

        int cnt = j - i;

        if (cnt > (n - a.size())) {
            cout << -1;
            return;
        }

        for (; i < j; ++i) a.push_back(c[i]);
    }

    for (auto e : a) 
        cout << e << ' ';
    cout << '\n';
    for (auto e : b) 
        cout << e << ' ';
    cout << '\n';

    // vi res = merge(a, b);
    // for (auto e : res)
    //     cout << e << ' ';
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
    