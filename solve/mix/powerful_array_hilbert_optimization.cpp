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

inline uint64_t hilbertorder(uint64_t x, uint64_t y) {
    const uint64_t logn = __lg(max(x, y) * 2 + 1) | 1;
    const uint64_t maxn = (1ull << logn) - 1;
    uint64_t res = 0;
    for (uint64_t s = 1ull << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
}

int block_size;
int a[200000];
vi lib;
int cnt[1000001] = {0};
ll ans = 0;

struct Query {
    int l, r, idx;
    int64_t ord;

    inline void calcOrder() {
        ord = hilbertorder(l, r);
    }

    bool operator<(Query other) const {
        return ord < other.ord;
    }
};

int getIdx(int e) {
    return e;
    // return lower_bound(all(lib), e) - lib.begin();
}

void add(int i) {
    int e = a[i]; // this is the power of one element. K_x^2 * a[i], since K_x is 1, its just a[i].
    int idx = getIdx(e);
    int curr = cnt[idx];
    ans += (1 * 1 * e) + (2 * 1 * curr * e);
    ++cnt[idx]; 
}

void remove(int i) {
    int e = a[i];
    int idx = getIdx(e);
    int curr = cnt[idx];

    ans += e * 1 * 1 - (2 * 1 * curr * e);
    --cnt[idx];
}

void init(int l, int r) {
    for (int i = l; i <= r; ++i) {
        add(i);
    }
}

ll get_answer() {
    return ans;
}

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    init(queries[0].l, queries[0].r);

    int cur_l = queries[0].l;
    int cur_r = queries[0].r;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

void solve() {
    int n, q;
    cin >> n >> q;

    block_size = sqrt(n);

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];

        // lib.push_back(e);
    }

    // sort(all(lib));
    // lib.erase(unique(all(lib)), lib.end());

    vector<Query> qs(q);
    int idx = 0;
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	--l, --r;

    	qs[idx] = {l, r, idx};
        qs[idx].calcOrder();
        ++idx;
    }

    vll ans = mo_s_algorithm(qs);
    for (auto res : ans) {
        cout << res << '\n';
    }
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
    