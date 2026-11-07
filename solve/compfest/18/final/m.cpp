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

bool solve() {
    int n;
    cin >> n;
    vi a(n), b(n);

    for (auto &e: a) {
        cin >> e;
    }

    for (auto & e : b) {
        cin >> e;
    }

    // only grows if terkena sinar mentari
    // terkena sinar mentari artinya batang di kanannya punya tinggi lebih kecil darinya
    // 3 2 1 -> can grow -> 4 3 2
    // 2 3 1 -> some can -> 2 4 2
    // 1 2 3 -> some can -> 1 2 4

    // a -> 1 2 3
    // b -> 1 3 4 -> can, 1 3 2 grow
    // b -> 1 2 4 -> 
    // b -> 2 2 4 -> fail, 1 cant grow without the rest growing
    // b -> 2 2 3 -> fail, 1 cant grow without the rest growing

    sort(all(a));
    sort(all(b));

    // a -> 1 2 2 3 4
    // b -> 1 2 3 3 4

    // a -> 1 2 4 5 
    // b -> 1 2 4 7

    // a -> 1 2 3 4 5
    // b -> 1 2 5 5 7

    // 1 2 3 4 5 
    // 1 2 6 5 4 
    // 1 2 5 7 5 
    // 1 2 5 5 7


    int debt = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = a[i];
        int y = b[i];

        if (y < x) return false;
        if (y == x) continue;

        x += debt;
        if (y == x) continue;
        if (y < x) continue; // can be paid by hiding behind largest.

        // y > x

        debt += y - x;
    }

    int last = a[n - 1] + debt;
    int needed = b[n - 1];


    return last <= needed;
}

signed main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "YA\n";
        else cout << "TIDAK\n";
    }
    return 0;
}
    