#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

#define uint unsigned int

void solve2() {
    int n;
    cin >> n;

    unordered_map<uint,uint> b;
    ull sum = 0;

    for (int i =0 ; i < n; ++i){
        uint e;
        cin >> e;
        sum += e;

        b[e] += 1;
    }

    if ((2 * sum) % n != 0) {
        cout << 0 << '\n';
        return;
    }

    ull target = (2 * sum) / n;
    ull ttl = 0;

    for (auto &[k, v] : b) {
        if (v == 0) continue;
        int y = target - k;

        if (k == y) {
            ttl += (ull) v * (v - 1) / 2;
            v = 0;
        } else {

            if (b.find(y) == b.end()) continue;

            uint &a = b.at(y);
            
            ttl += (ull) v * a;
            a = 0;
            v = 0;
        }
    }    

    cout << ttl << '\n';
}

void solve() {
    int n;
    cin >> n;

    vi a(n);

    ull sum = 0;
    for (auto & e : a) {
        cin >> e;
        sum += e;
    }

    if ((2 * sum) % n != 0) {
        cout << 0 << '\n';
        return;
    }

    sort(all(a));

    ull target = (2 * sum) / n;
    ull ttl = 0;

    vector<pair<int, int>> f;

    for (int i =0 ; i < n;) {
        int j = i;
        while (j < n && a[i] == a[j]) ++j;

        f.push_back({a[i], j - i});
        i = j;
    }

    int l = 0, r = f.size() - 1;
    while (l <= r) {
        pair<int, int> left = f[l], right = f[r];
        ull x = left.first;
        ull y = right.first;

        if (x + y < target) ++l;
        else if (x + y > target) --r;
        else {
            if (l == r) {
                ull c = left.second;
                ttl += (ull) c * (c - 1) / 2;
            } else {
                ttl += (ull) left.second * right.second;
            }
            ++l, --r;
        }
    }

    cout << ttl << '\n';
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
    