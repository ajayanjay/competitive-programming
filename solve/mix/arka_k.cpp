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

void solve() {
    int n, a;
    cin >> n >> a;

    string s;
    cin >> s;

    int length = 26;
    vector<vi> w(length, vi(length));
    vector<pair<int, int>> mins(length);

    for (int i = 0; i < length; ++i) {
    	pair<int, int> mn = {0, 0};
    	for (int j = 0; j < length; ++j) {
    		cin >> w[i][j];
    		
    		if (w[mn.first][mn.second] > w[i][j]) {
    			mn.first = i;
    			mn.second = j;
    		}
    	}
    	mins[i] = mn;
    }

	int l = 0, r = n - 1;
	int m = 0; // mode
	pair<int, int> p = {0, 0}; // [0,0]
	int c = a; // cost for mode swapping

	// mode 1 = push_back, mode 2 = push_front

	/*
	candidate 1: min r // low pr
	candidate 2: W_r + W_(r - 1) // high pr
	candidate 3: min l // low pr
	candidate 4: W_l + W_(l + 1) // high pr
	candidate 5: r + l + cost // low pr
	*/

	while (l <= r) {

		// min r
		int r_idx = s[r] - 'a';
		pair<int, int> p_c_1 = mins[r_idx];
		int c_1 = (p_c_1 == p ? 0 : w[p_c_1.first][p_c_1.second]) + (!m ? 0 : c);

		// r + r - 1
		pair<int, int> p_c_2 = {s[r] - 'a', s[r - 1] - 'a'};
		int c_2 = (p_c_2 == p ? 0 : w[p_c_2.first][p_c_2.second]) + (!m ? 0 : c);

		// min l
		int l_idx = s[l] - 'a';
		pair<int, int> p_c_3 = mins[l_idx];
		int c_3 = (p_c_3 == p ? 0 : w[p_c_3.first][p_c_3.second]) + (m ? 0 : c);

		// l + l + 1
		pair<int, int> p_c_4 = {s[l] - 'a', s[l + 1] - 'a'};
		int c_4 = (p_c_4 == p ? 0 : w[p_c_4.first][p_c_4.second]) + (m ? 0 : c);

		// r + l + c
		pair<int, int> p_c_5 = {l_idx, r_idx};
		int c_5 = (p_c_5 == p ? 0 : w[p_c_5.first][p_c_5.second]) + c;



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
    