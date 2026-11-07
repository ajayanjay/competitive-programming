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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> c;
    c.push_back(s[0] - '0');

    int c_ptr = 0;

    for (int i = 1; i < n; ++i) {
    	bool curr = s[i] - '0';
    	if (curr != c[c_ptr]) {
    		c.push_back(curr);
    		++c_ptr;
    	}
    }

    if (c.size() == 1) {
    	cout << 0 << '\n';
    	return;
    }

    // the only possible appearance of 1 is in either first or second.
    bool first_1 = c[0] == 1;
    
    cout << (c.size() - 2 + first_1) << '\n';

    // a repeating sequence doesnt matter since the "reduced" version is the same for all
    // 0101010 = 010101 + 1 == 01010 + 2 == 0101 + 3 = 010 + 4 = 01 + 5
    // 1010101 = 101010 + 1 == 10101 + 2 == 1010 + 3 = 101 + 4 = 10 + 5 = 01 + 6
    // 010101 = 01010 + 1 = 0101 + 2 = 010 + 3 = 01 + 4
    // 101010 = 10101 + 1 = 1010 + 2 = 101 + 3 = 10 + 4 = 01 + 5

    // 0101010	1010101	101010 	010101
    // 0110101	1101010	110101 	011010
    // 0111010	1110101	111010 	011101
    // 0111101	1111010	111101 	011110
    // 0111110	1111101	111110 	000001
    // 0000001	1111110	000001  
    //			0000001	
    
    
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    