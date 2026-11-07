#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int combine(int a, int b) {
        return a + b;
    }

    int make_node(int item) {
        return item;
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) tree[node] = make_node(arr[start]);
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // single point update.
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
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int query() { return query(0, n - 1); }

    void update(int pos, int newVal) { update(1, 0, n - 1, pos, newVal); }
};