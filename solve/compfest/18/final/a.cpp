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

struct DSU {
    vector<int> parent, sz;
    
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (sz[px] < sz[py]) swap(px, py);
        parent[py] = px;
        sz[px] += sz[py];
        return true;
    }

    int getSize(int x) {
        return sz[find(x)];
    }
    
    bool connected(int x, int y) { return find(x) == find(y); }
};

vector<int> leastPrimeFactor(int n) {

    vector<int> lpf(n + 1);
    for (int i = 0; i <= n; i++) {
        lpf[i] = i;
    }

    lpf[0] = 0;
    lpf[1] = 1; 
    
    for (int i = 2; i <= n; i++) {

        if (lpf[i] == i) {
            for (int j = i * 2; j <= n; j += i) {
                if (lpf[j] == j) {
                    lpf[j] = i;
                }
            }
        }
    }

    return lpf;
}

vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}

vector<int> primes(vector<bool> &isPrime, int maxN) {
    vi res;
    for (int i = 2; i <= maxN; ++i) {
        if (isPrime[i]) {
            res.pb(i);
        }
    }

    return res;
}

vector<pii> factors(int x, vi &primes) {

    vector<pii> res;
    for (auto i : primes) {
        if (i * i > x) break;
        if (x % i == 0) {
            int num = i;

            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                ++cnt;
            }

            res.pb({num, cnt});
        }
        if (x <= 1) break;
    }

    if (x > 1) res.pb({x, 1});

    return res;
}

bool solve() {
    int n, k;
    cin >> n >> k;

    vector<bool> isPrime = sieve_of_eratosthenes(1e6);
    vi ps = primes(isPrime, 1e6);

    vi a(n);
    DSU ds(1e6 + 1);
    vector<bool> vis(1e6 + 1);
    for (auto &e: a) {
        cin >> e;

        if (!isPrime[e] && !vis[e]) {
            vis[e] = true;
            vector<pii> fs = factors(e, ps);
            for (auto [num, p]: fs) {
                ds.unite(e, num);
            }
        }
    }

    vector<vi> grp(1e6 + 1);
    for (auto e : a) {
        grp[ds.find(e)].pb(e);
    }

    for (auto & x : grp) {
        if (x.empty()) continue;

        int k_temp = k;
        for (auto e : x) {
            k_temp = k_temp / gcd(e, k_temp);
            if (k_temp <= 1) return true;
        }
    }

    return false;
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
