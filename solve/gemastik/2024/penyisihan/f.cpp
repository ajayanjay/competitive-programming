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
    int n, p, q;
    cin >> n >> p >> q;

    int mnP = 2 * p;
    int mnQ = ceil((3 * q) / 2);

    while (n--) {
        int e;
        cin >> e;

        int res = 0;
        while (e % 2 == 0 && e >= mnP) {
            e /= 2;
            res += p;
        }

        while (e % 3 == 0 && e >= mnQ) {
            e /= 3;
            res += q;
        }

        res += e;

        cout << res << '\n';

        /*
            all sunshine and rainbow until i realize you can subtract by 1
            in the middle, 
            peluru: 1
            e -> (e - 1)

            bom kecil: p, 1/2 = 0.5
            e % 2 == 0
            e -> (e / 2)

            bom besar: q, 1/3 = 0.333
            e % 3 == 0
            e -> (e / 3)

            base case
            if e < p and e < q
            use peluru -> e
            O(1)

            brute force approach
            
            compare ratio for all three and take the most beneficial one
            example: 

                P = 4
                6 -> 3 (minus 3, but cost 4) hence min 2P

                Q = 5
                3 -> 1 (minus 2, cost 1) hence min (3/2)Q:

                90, P: 3, Q: 5

                p1: 90 -> 90 (1: 1)
                p2: 45 -> 3  (15 : 1)
                p3: 60 -> 5  (12 : 1)
                take p2 -> +3

                45
                p1: 45 -> 45 (1 : 1)
                p3: 30 -> 5 (6 : 1)
                take p3 -> +5

                15
                p1: 15 -> 15 (1 : 1)
                p3: 10 -> 5 (2 : 1)
                take p3 -> +5

                5
                p1: 5 -> 5 (1 : 1)
                take p1 -> +5

                order doesn't matter... it seems..

                2P -> minimum for half, lower is not worth it.
                (3/2)Q -> minimum for thrif (what the fuck is thrif), lower is not worth

                instead of halfing each time O(Log2 Ai)
                we can just find the maximum amount of halv and thriv (what the fuck is thriv)
                mathematically.

                p2: 2P is the minimum -> must find the closest continous half of Ai above 2P.
                p3: (3/2)Q is the minimum -> must find the closest continous thrif of Ai above (3/2)P.

                or.. we can just half until the next one is invalid..
        */
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
    