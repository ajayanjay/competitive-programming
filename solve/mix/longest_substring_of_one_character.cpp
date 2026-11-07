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

struct _t {
	char leftChar, rightChar;
	int leftLength, rightLength, maxLength;
	bool connected; // if leftChar until rightChar is of the same character.

};

struct SegTree {
    int n;
    vector<_t> tree;
    
    SegTree(string& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    _t combine(_t a, _t b) {

    	if (a.leftChar == -1) return b;
    	if (b.leftChar == -1) return a;

    	_t res = {
    		.leftChar = a.leftChar,
    		.rightChar = b.rightChar,
    		.leftLength = a.leftLength,
    		.rightLength = b.rightLength,
    		.maxLength = max(a.maxLength, b.maxLength),

    		// if a and b is connected, and has the same char, new string must be of the same char
    		.connected = (a.connected && b.connected && a.leftChar == b.rightChar)
    	};

    	if (res.connected) {
    		res.leftLength = res.rightLength = (a.leftLength + b.leftLength);
    		res.maxLength = max(res.maxLength, res.leftLength);
    		return res;
    	}

    	// not connected either a or b isnt connected.

    	if (a.rightChar == b.leftChar) { // can combine
    		int combinedLength = a.rightLength + b.leftLength;
    		if (combinedLength > res.maxLength) {
    			res.maxLength = combinedLength;
    		}

    		if (a.connected)
    			res.leftLength = res.maxLength;
    		if (b.connected)
    			res.rightLength = res.maxLength;
    	}

		return res;        
    }

    _t make_node(char item) {
        return {
        	.leftChar = item,
        	.rightChar = item,
        	.leftLength = 1,
        	.rightLength = 1,
        	.maxLength = 1,
        	.connected = true
        };
    }
    
    void build(string& arr, int node, int start, int end) {
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
    
    _t query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {-1};
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;

        _t left = query(2 * node, start, mid, l, r);
        _t right = query(2 * node + 1, mid + 1, end, l, r);

        return combine(left, right);
    }
    
    int query(int l, int r) { return query(1, 0, n - 1, l, r).maxLength; }
    int query() { return query(0, n - 1); }

    void update(int pos, int newVal) { update(1, 0, n - 1, pos, newVal); }
};

vector<int> longestRepeating(string s, vector<char> queryCharacters, vector<int>& queryIndices) {

	SegTree st(s);

	int q = queryCharacters.size();

	vector<int> res;

	for (int i = 0; i < q; ++i) {
		int idx = queryIndices[i];
		char c = queryCharacters[i];

		st.update(idx, c);
		res.push_back(st.query());
	}

	return res;
}

void solve() {
    
	string s;
	cin >> s;

	int q;
	cin >> q;

	vector<char> queryChars(q);
	vector<int> queryIndices(q);


	for (int i = 0; i < q; ++i) {
		int e;
		char c; 

		cin >> e >> c;

		queryChars[i] = c;
		queryIndices[i] = e;
	}

	vector<int> res = longestRepeating(s, queryChars, queryIndices);

	for (auto e : res) {
		cout << e;
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
