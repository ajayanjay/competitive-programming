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

struct _t {
    int lp, rp;
    int cnt;
};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(string &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t left, _t right) {
        // right's right par can be paired with left' left par
        // left' left par should not affect right' right par.

        if (left.lp == -1) return right;
        if (right.lp == -1) return left;

        int parCnt = min(left.lp, right.rp);

        return {
            .lp = left.lp - parCnt + right.lp,
            .rp = right.rp - parCnt + left.rp,
            .cnt = left.cnt + right.cnt + (parCnt * 2),
        };
    }

    _t make_node(char item) {
        return {
            .lp = (item == '(' ? 1 : 0),
            .rp = (item == ')' ? 1 : 0),
            .cnt = 0
        };
    }
    
    void build(string &arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int position, int newValue) {
        if (start == end) tree[node] = make_node(newValue);
        else {
            int mid = (start + end) / 2;
            if (position <= mid)
                update(node * 2, start, mid, position, newValue);
            else
                update(node * 2 + 1, mid + 1, end, position, newValue);

            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }
    
    _t query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {-1, -1, -1};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r).cnt; }
    int query() { return query(0, n - 1); }
};

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;

    SegTree st(s);

    while (q--) {
        int l, r;
        cin >> l >> r;

        --l, --r;

        cout << st.query(l, r) << '\n';
    }
}

// // Useful macros
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define pb push_back
// #define mp make_pair
// #define fi first
// #define se second
// #define sz(x) (int)(x).size()

// // Loop macros
// #define rep(i, a, b) for(int i = a; i < b; i++)
// #define per(i, a, b) for(int i = a; i >= b; i--)
// #define trav(a, x) for(auto& a : x)

// // Debug macro
// #ifdef LOCAL
//     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
// #else
//     #define debug(x...)
// #endif

// // Constants
// const int MOD = 1e9 + 7;
// const int MOD2 = 998244353;
// const int INF = 1e9;
// const ll LINF = 1e18;
// const ld EPS = 1e-9;
// const ld PI = acos(-1);

// // Directions (4-directional)
// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

// // Directions (8-directional)
// int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// // Utility functions
// template<typename T>
// void _print(T t) { cerr << t << "]" << endl; }

// template<typename T, typename... Args>
// void _print(T t, Args... args) { cerr << t << ", "; _print(args...); }

// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// ll power(ll a, ll b, ll mod = MOD) {
//     ll res = 1;
//     a %= mod;
//     while (b > 0) {
//         if (b & 1) res = res * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return res;
// }

// ll modInverse(ll a, ll mod = MOD) {
//     return power(a, mod - 2, mod);
// }

// // Check if point is inside bounds
// bool isValid(int x, int y, int n, int m) {
//     return x >= 0 && x < n && y >= 0 && y < m;
// }

// // String to integer conversion
// int toInt(string s) {
//     int res = 0;
//     for (char c : s) res = res * 10 + (c - '0');
//     return res;
// }

// // Integer to string conversion
// string toString(ll n) {
//     if (n == 0) return "0";
//     string s = "";
//     while (n > 0) {
//         s = char('0' + n % 10) + s;
//         n /= 10;
//     }
//     return s;
// }

// // Binary search template
// template<typename T>
// ll binarySearch(ll l, ll r, T check) {
//     while (l < r) {
//         ll mid = l + (r - l) / 2;
//         if (check(mid)) r = mid;
//         else l = mid + 1;
//     }
//     return l;
// }

// // Prefix sum template
// template<typename T>
// vector<T> prefixSum(vector<T>& arr) {
//     int n = sz(arr);
//     vector<T> prefix(n + 1, 0);
//     rep(i, 0, n) prefix[i + 1] = prefix[i] + arr[i];
//     return prefix;
// }

// struct _t {
//     int left_par, right_par, cnt;
// };

// // Segment Tree template (basic)
// struct SegTree {
//     int n;
//     vector<_t> tree;
    
//     SegTree(string& arr) {
//         n = sz(arr);
//         tree.resize(4 * n);
//         build(arr, 1, 0, n - 1);
//     }

//     _t combine(_t left, _t right) {
//         int cnt = left.cnt + right.cnt;
//         int left_par = left.left_par;
//         int right_par = right.right_par;

//         if (left_par >= right_par) {
//             cnt += 2 * right_par;
//             left_par -= right_par;
//             right_par = 0;
//         } else {
//             cnt += 2 * left_par;
//             right_par -= left_par;
//             left_par = 0;
//         }

//         return {.left_par = left_par + right.left_par, .right_par = right_par + left.right_par, .cnt = cnt};
//     }
    
//     void build(string& arr, int node, int start, int end) {
//         if (start == end) {
//             if (arr[start] == '('){
//                 tree[node].left_par = 1;
//                 tree[node].right_par = 0;
//             }
//             else {
//                 tree[node].right_par = 1;
//                 tree[node].left_par = 0;
//             }
//             tree[node].cnt = 0;
//         }
//         else {
//             int mid = (start + end) / 2;
//             build(arr, 2 * node, start, mid);
//             build(arr, 2 * node + 1, mid + 1, end);

//             tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
//         }
//     }
    
//     _t query(int node, int start, int end, int l, int r) {
//         if (r < start || end < l) return {-1, -1, -1};
//         if (l <= start && end <= r) return tree[node];
//         int mid = (start + end) / 2;

//         _t left = query(2 * node, start, mid, l, r);
//         _t right = query(2 * node + 1, mid + 1, end, l, r);

//         if (left.cnt == -1) {
//             return right;
//         } else if (right.cnt == -1)  {
//             return left;
//         }
//         return combine(left, right);
//     }
    
//     int query(int l, int r) { return query(1, 0, n - 1, l, r).cnt; }
// };

// void solve() {
//     string sybau;
//     cin >> sybau;

//     SegTree s(sybau);

//     int m;
//     cin >> m;
//     while (m--) {
//         int l, r;
//         cin >> l >> r;

//         cout << s.query(--l,--r) << '\n';
//     }


// }

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