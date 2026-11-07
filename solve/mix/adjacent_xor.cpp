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

// Segment Tree template (basic)
struct SegTree {
    int n;
    vi tree;
    
    SegTree(vi& arr) {
        n = sz(arr);
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    
    void build(vi& arr, int node, int start, int end) {
        if (start == end) tree[node] = arr[start];
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + 
               query(2 * node + 1, mid + 1, end, l, r);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
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
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (auto& x : a)
        cin >> x;

    for (int i =0 ; i < n - 1 ; ++ i)
        a[i + 1] += a[i];

    cout << a[n - 1] << '\n';
}

int main() {
    FAST_IO;
    
    ll t = 1;
    cin >> t;
    
    while (t--) {
        solve();

        // if (solve())
        // printf("Yes\n");
        // else 
        // printf("No\n");
    }
    
    return 0;
}