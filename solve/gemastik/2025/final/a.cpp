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

int getNum(int i, int t, int k) {

    if (t < i) {
        int res = 0;
        for (int e = 1; e * e <= i && e <= t; ++e) {
            if (i % e == 0) {
                int x = i / e;
                if (x == e) ++res;
                else {
                    if (x <= t) ++res;
                    ++res;
                }
            }
        }
        return res;
    }

    // process above
    int above = floor(t / i);

    if (above > k) return above;

    // process under
    int under = i == 1 ? 0 : 1;
    for (int e = 2; e * e <= i; ++e) {
        if (i % e == 0) {
            int x = i / e;
            if (x == e) ++under;
            else under += 2;
        }
    }

    return under + above;
}

void solve() {
    int n, t, k;
    cin >> n >> t >> k;

    int res = 0;
    for (int i = 1 ; i <= n; ++i) {
        int e = getNum(i, t, k);
        // cout << i << ' ' << e << '\n';

        if (e <= k) {
            ++res;
        }
    }

    cout << res;

    /*
        two cases:
        t < i and t >= i

        if t < i
            count how many number from 1 to t divides i
            the same as finding all factor of i

        else t >= i
            count how many number from t to T divisible by i

            the easy way is to find lower bound of i * x <= T -> x <= T / i,
            x is the count, but since x must be an integer
            x <= floor(T / i)



    */
}

void solve2() {
    int n, t, k;
    cin >> n >> t >> k;

    /*

    t < i:

    t >= i: floor(T / i)

    */
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
    