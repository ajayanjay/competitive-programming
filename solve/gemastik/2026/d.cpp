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

int getMin(int e, int damage, int poisonTurns) {
    if (e <= damage) return 1;
    if (damage < 4 || poisonTurns <= 4) {
        return e / damage + (e % damage == 0 ? 0 : 1);
    }

    // e > damage && poisonTurns > 4
    int res = 0;

    int hitBase = e / damage + (e % damage == 0 ? 0 : 1);
    if (hitBase <= 4) {
        return hitBase;
    }

    int poisonedHit = damage + (damage / 4);
    int TotalPoisonedDamage = poisonTurns * poisonedHit;

    if (e % TotalPoisonedDamage == 0) {
        int totalCycle = e / TotalPoisonedDamage;
        int turns = totalCycle * (poisonTurns + 1);
        return turns;
    } else {
        int totalCycle = e / TotalPoisonedDamage;
        int damage = totalCycle * TotalPoisonedDamage;
        e -= damage;

        int turns = totalCycle * (poisonTurns + 1);
        res += turns;
    }

    // e < totalpoisoneddamage
    hitBase = e / damage + (e % damage == 0 ? 0 : 1);
    int hitPoison = (e / poisonedHit + (e % poisonedHit == 0 ? 0 : 1)) + 1;

    res += min(hitBase, hitPoison);
    return res;
}

void solve() {
    int n, v, o;
    cin >> n >> v >> o;
    // n -> jumlah musuh, v -> besar demeg, m -> banyak operasi posion

    int res = 0;
    for (int i =0 ; i < n ; ++ i) {
        int e; cin >> e;

        res += getMin(e, v, o);
    }
    cout << res;
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
    