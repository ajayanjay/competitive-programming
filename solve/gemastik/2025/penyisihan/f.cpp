#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Common shortcuts
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vs vector<string>
#define vb vector<bool>

// Useful macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()

// Loop macros
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define trav(a, x) for(auto& a : x)

// Debug macro
#ifdef LOCAL
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
    #define debug(x...)
#endif

// Constants
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1);

// Directions (4-directional)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Directions (8-directional)
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Utility functions
template<typename T>
void _print(T t) { cerr << t << "]" << endl; }

template<typename T, typename... Args>
void _print(T t, Args... args) { cerr << t << ", "; _print(args...); }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod);
}

// Check if point is inside bounds
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// String to integer conversion
int toInt(string s) {
    int res = 0;
    for (char c : s) res = res * 10 + (c - '0');
    return res;
}

// Integer to string conversion
string toString(ll n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s = char('0' + n % 10) + s;
        n /= 10;
    }
    return s;
}

// Binary search template
template<typename T>
ll binarySearch(ll l, ll r, T check) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

// Prefix sum template
template<typename T>
vector<T> prefixSum(vector<T>& arr) {
    int n = sz(arr);
    vector<T> prefix(n + 1, 0);
    rep(i, 0, n) prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}

struct Node {
    int val;
};

struct SegTree {
    int n;
    vector<Node> seg;
    vector<char> module;
    vector<int> k;

    SegTree(int n, vector<char> &mod, vector<int> &val) : n(n), module(mod), k(val) {
        seg.resize(4*n);
        build(1, 0, n-1);
    }

    int combine(int left, int right, char op) {
        if (op == '+') return (left + right) % 16;
        else return left ^ right;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id].val = k[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        // combine left and right, but careful:
        // since each element has its own operator,
        // we can consider module[mid+1] (or define how ops apply between them)
        seg[id].val = combine(seg[id*2].val, seg[id*2+1].val, module[mid+1]);
    }

    void update(int id, int l, int r, int pos, char op, int val) {
        if (l == r) {
            k[l] = val;
            module[l] = op;
            seg[id].val = val;
            return;
        }
        int mid = (l+r)/2;
        if (pos <= mid) update(id*2, l, mid, pos, op, val);
        else update(id*2+1, mid+1, r, pos, op, val);
        seg[id].val = combine(seg[id*2].val, seg[id*2+1].val, module[mid+1]);
    }

    int query() {
        return seg[1].val;
    }
};


// Union-Find (Disjoint Set Union)
struct DSU {
    vi parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        rep(i, 0, n) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
    
    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<char> module(n);
    vector<int> k(n);

    for (int i = 0; i < n; ++i) {
    	cin >> module[i] >> k[i];
    }

    SegTree t(n, module, k);

    while (q--) {
    	int idx, num;
    	char modul;

    	cin >> idx >> modul >> num;

    	--idx;

    	t.update(1, 0, n -1, idx, modul ,num);
    	cout << t.query() << '\n';
    }
}

int main() {
    FAST_IO;
    
    ll t = 1;
    // cin >> t;
    
    while (t--) {
        solve();

        // if (solve())
        // printf("Yes\n");
        // else 
        // printf("No\n");
    }
    
    return 0;
}