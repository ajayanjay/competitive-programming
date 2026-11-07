#include <bits/stdc++.h>
using namespace std;

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
};