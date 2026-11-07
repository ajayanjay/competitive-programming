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

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode * l, ListNode * r) {
	if (!l) return r;
	if (!r) return l;

	ListNode * left = l;
	ListNode * right = r;
	ListNode * merged = nullptr;

	// merge r and l into merged

	if (left->val <= right->val) {
		merged = left;
		left = left->next;
	} else {
		merged = right;
		right = right->next;
	}

	ListNode * m = merged;

	while (left && right) {
		if (left->val <= right->val) {
			m->next = left;
			left = left->next;
		} else {
			m->next = right;
			right = right->next;
		}
		m = m->next;
	}

	while (left) {
		m->next = left;

		left = left->next;
		m = m->next;
	}

	while (right) {
		m->next = right;

		right = right->next;
		m = m->next;
	}

	return merged;
}

ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) {
	if (l > r) return nullptr;
	if (l == r) return lists[r];

	int m = (l + r) / 2;
	ListNode* left = mergeSort(lists, l, m);
	ListNode* right = mergeSort(lists, m + 1, r);

	return merge(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	return mergeSort(lists, 0, lists.size() - 1);
}

void solve() {

	int n;
	cin >> n;

	vector<ListNode*> l(n, nullptr);
	for (auto &ln: l) {
		int m;
		cin >> m;

		ListNode * t = ln;

		while (m--) {
			int e;
			cin >> e;

			ListNode* x = new ListNode(e);
			t = x;
			t = t->next;
		}
	}

	ListNode* res = mergeKLists(l);

	ListNode * t = res;
	while (t) {
		cout << t->val << ' ';
		t = t->next;
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
