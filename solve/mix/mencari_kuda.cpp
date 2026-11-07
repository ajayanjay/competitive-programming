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

// horse starts at 0.0
bool isHorseStepable(int x, int y) {

}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
    	int x, y;
    	cin >> x >> y;

    }

    // step x 2.
    // stepA (x,y) -> (x + 2, y + 1): y = 2x
    // stepB (x,y) -> (x + 1, y + 2): y = 1/2x

    // to get from 0,0 to M,N
    // we have to use a combination of i stepA and j stepB
    // (M, N) -> (2i + j, i + 2j)
    // M = 2i + j, N = i + 2j

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
    