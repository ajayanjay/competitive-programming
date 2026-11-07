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
#define ull unsigned ll

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(vector<int>& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);
        build(arr);
    }

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void build(vector<int>& arr) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += arr[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    long long query(int i) {
        long long res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }

    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void reset() {
        for (auto & e : bit)
            e = 0;
    }
};

ull factorial(int n) {
	if (n == 1 || n == 0) return 1;

	ull res = 1;
	for (int i = 2; i <= n; ++i)
		res *= i;

	return res;
}

ull factorial(int left, int right) {
	ull res = 1;

	for (int i = max(left, 1); i <= right; ++i)
		res *= i;

	return res;
}

ull C(int n, int K) {

	int mx = max(n, K);
	int mn = min(n, K);

	return factorial(mn, mx) / factorial(mn);
}


void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (auto & e : a)
        cin >> e;

    Fenwick fw(n);
    vector<vector<ull>> dp(k + 1, vector<ull>(n));

    for (int i = 0; i < n; ++i)
        dp[0][i] = 1;

    // i < j
    // a[i] < a[i2] < ... < a[ik] 
    for (int len = 1; len <= k; ++len) {
        fw.reset();
        for (int i = 0; i < n; ++i) {
            dp[len][i] = fw.query(a[i] - 1);;
            fw.update(a[i], dp[len - 1][i]);
        }
    }

    ull res= 0;
    for (int i = 0 ; i < n; ++i)
        res += dp[k][i];

    cout << res;






    // 0 0 0 0 0
    // 1 0 0 0 0
    // 2 1 0 0 0
    // 3 2 1 0 0
    // 4 3 2 0 1
    // 5 4 3 1 1
    // 4 3 2 0 0

    // 1 4 9 8 2 3 5 7 6
    // 0 0 0 0 0 0 0 0 0
    // 1 0 0 0 0 0 0 0 0
    // 2 0 0 1 0 0 0 0 0
    // 3 0 0 2 0 0 0 0 1
    // 4 0 0 3 0 0 0 1 1
    // 5 1 0 3 0 0 0 1 1
    // 5 2 1 3 0 0 0 1 1
    // 6 3 2 4 1 0 0 1 1
    // 7 4 3 5 2 0 1 1 1
    // 8 5 4 6 3 1 1 1 1





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
    