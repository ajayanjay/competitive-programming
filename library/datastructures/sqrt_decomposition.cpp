#include <bits/stdc++.h>
using namespace std;

// sort the queries efficiently, then traverse through each queries using the last query to answer the next one.

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

// use hilbert' order, fastest one i could find.
struct Query {
    int l, r, idx;
    int64_t ord;

    Query(int l, int r, int idx) : l(l), r(r), idx(idx) { calcOrder(); }

    inline void calcOrder() {
        ord = hilbertorder(l, r);
    }

    bool operator<(Query other) const {
        return ord < other.ord;
    }
};

void add(int i); // add ith element to data structure
void remove(int i); // remove ith element from data structure
int get_answer(); // fetch answer from data structure
void init(int l, int r);

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end()); // sort using operator, using hilbert' order.

    /*  using block size, slower alternative to hilbert
        int n; // size of the array.
        const int BLOCK_SIZE = sqrt(n); // must use const for faster comparison.

        sort(queries.begin(), queries.end(), [&](Query &p, Query &q) {
            int block_p = p.l / BLOCK_SIZE;
            int block_q = q.l / BLOCK_SIZE;

            if (block_p != block_q) return block_p < block_q;

            return (block_p & 1)
                ? (p.r < q.r)
                : (p.r > q.r);
        });
    */

    // TODO: initialize data structure
    init(queries[0].l, queries[0].r); // example initialize from the first query.

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