#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    vector<int> lazy;
    
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int combine(int a, int b) {
        return min(a, b);
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

    void push(int v) {
        tree[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        tree[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            tree[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
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
    
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -1;
        if (l == tl && tr == r)
            return tree[v];

        push(v);
        int tm = (tl + tr) / 2;

        return combine(
            query(v*2, tl, tm, l, min(r, tm)), 
            query(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int query() { return query(0, n - 1); }

    void update(int l, int r, int v) { update(1, 0, n - 1, l, r, v); }
};