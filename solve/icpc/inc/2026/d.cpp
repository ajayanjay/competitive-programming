#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;

    vi a(n + 1);
    int moves = 0;
    int self = 0;
    for (int i = 1; i <= n; ++i) {
        int e;
        cin >> e;

        a[i] = e;

        if (e <= n) {
            ++moves;
            if (i > n / 2 && e == i) ++self;
        }
    }

    if (moves == self) {
        if (moves % 2 == 0) {
            cout << "Tresno\n";
        } else {
            cout << "Fausta\n";
        }
        return;
    }
    else {
        cout << "Draw\n";
        return;
    }




    /*
        if theres a possible draw, its a draw, 
        because the player can just do the draw move so the game has to 
        switch turns, since both doesnt want to lose, they draw anyways

        to find out if A is draw able, we can just
        find out if fausta or tresno will definitely win, a complement.
    */

    /*
        fausta will win if theres only one move (exactly 1 1)
        tresno will win if theres no move
        etc is draw.
    */


    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // switch(solve()) {
        // case -1: {
        //     cout << "Draw\n"; 
        //     break;
        // }
        // case 0: {
        //     cout << "Tresno\n"; 
        //     break;
        // }
        // case 1: {
        //     cout << "Fausta\n"; 
        //     break;
        // }
        // }
    }
}