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

bool mp[500000];

int getIdx(int e, char o) { // convert -200018 to 0, 200018 to 400036
    if (o == '-') {
        e = - e - 1;
    }

    return e + 200050;
}

int fromIdx(int i, char o) {
    if (o == '+') {
        return 200050 - i;
    } else {
        return i - 200050 + 1;
    }
}

int add(int e, char o) {
    int i = getIdx(e, o);
    switch (o) {
    case '+': {
        while (mp[i]) {
            mp[i++] = 0;
        }
        mp[i] = 1;
    }
    case '-': {
        while (mp[i]) {
            mp[i--] = 0;
        }
        mp[i] = 1;
    }
    }

    return i;
}

void solve() {
    int q;
    cin >> q;

    int cnt = 0;
    while (q--) {
        char o;
        int e;
        cin >> o >> e;

        int i = add(e, o);
        int f = fromIdx(i, o);

        int check = getIdx(f, e == '+' ? '-' : '+');
        if (mp[check] == 1) --cnt;
        else ++cnt;

        if (cnt == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }


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
    