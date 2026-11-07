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

ull toUll(string s) {
    ull res = 0;
    for (char c : s) res = res * 10 + (c - '0');
    return res;
}

ull intLength(ull i) {
    int l=0;
    for(;i;i/=10) l++;
    return l==0 ? 1 : l;
}


ull magic_subtraction(ull n) {

	ull cnt = 0;

	string s = to_string(n);
	pair<int, int> mx = {0, 0};
	for (int i = 0; i < (int) (s.size() - 2); ++i) {
		if ((s[i] - '0') > mx.first){
			mx.first = s[i] - '0';
			mx.second = i;
		}
	}
	
	if (mx.first == 9) { // best case.
		ull t = toUll(s.substr(mx.second));

		cnt += t / 9;
		t %= 9;

		s = s.substr(0, mx.second + 1);
		s[mx.second] = t;
	}

	while (n > 0) {

		s = to_string(n);
		mx = {0, -2};
		for (int i = 0; i < (int) (s.size() - 2); ++i) {
			if ((s[i] - '0') > mx.first) {
				mx.first = s[i] - '0';
				mx.second = i;
			}
		}
		 
		int touch = s.size();
		while (n > 0 && touch != (mx.second + 1)) {

			int first = mx.first;
			int second = n % 10;
			int third = ((n % 100) / 10);

			int mx_digit = max(first, max(second, third));

			n -= mx_digit;
			
			touch = intLength(n);

			++cnt;
		}	
	}
	return cnt;
}

void probably_faster(ull n) {
	// the idea is

	/*
	while n > 0
		max_digit = max of n from 0...length - 2

		if max_digit = 9
			deletes everything after max_digit
		else if max_digit = 8 and digit is even
			deletes evertything after max_digit
		else
			max_digit is a candidate max
			
			while n > 0
				we take max from max_digit, last_digit, second_last_digit
				 

				subtract n with max
			

	*/
}

void solve() {
    ull n;
    cin >> n;

    ull cnt = 0;

    while (n > 0) {
        ull x = n;
        int max_digit = 0;
        while (x > 0) {
            max_digit = max(max_digit, (int)(x % 10));
            x /= 10;
        }

        n -= max_digit;
        cnt++;
    }

    cout << cnt;
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
    