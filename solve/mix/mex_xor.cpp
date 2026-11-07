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

#define MAX_N 200000

#include <bits/stdc++.h>
using namespace std;

struct Mex {
	set<int> missing;
	set<int> available;

	Mex(vector<int> const& A) {
		for (int i = 0; i <= A.size(); ++i) {
			missing.insert(i);
		}

		for (int x : A) {
			missing.erase(x);
		}
	}

	Mex(int MAX_SIZE) {
		for (int i = 0; i <= MAX_SIZE; ++i) {
			missing.insert(i);
		}
	}

	int mex() {
		return *missing.begin();
	}

	bool hasElement(int x) {
		return available.find(x) != available.end();
	}

	void update(int x) {
		if (hasElement(x)) {
			available.erase(x);
			missing.insert(x);
		} else {
			available.insert(x);
			missing.erase(x);
		}
 	}

 	set<int> getMissing() {
 		return missing;
 	}

 	set<int> getAvailable() {
 		return available;
 	}
};

void solve2() {

	// set<int> s;
	// Mex m1(MAX_N + 1), m2(MAX_N + 1);
	
	// int q, k;
	// cin>> q >> k;
	// while (q--) {
	// 	int x;
	// 	cin >> x;

	// 	if (s.find(x) != end(s)) { // existing element
	// 		s.erase(x);

	// 		m1.remove(x);
	// 		m2.remove(x ^ k);

	// 	} else { // new element
	// 		s.insert(x);
			
	// 		m1.insert(x);
	// 		m2.insert(x ^ k);
	// 	}

	// 	if (m1.mex() <= k) { // S = {0, 1}, K = 2 -> 0
	// 		cout << 0 << '\n';
	// 		continue;
	// 	}

	// 	cout << m2.mex() << '\n';
	// }

	/*
	to conclude, on each iteration we
	put x into the array

	M: current mex after insertion.
	K: the.. thing.

	if M < K: result = 0.


	
	*/

	// {0, 1, ..., n}
	// x ^ k == 0 if x == k.
	// 0 1 2 3 => MEX = 4.
	// 0 1 2 3 -> 4
	// 1 0 3 2 -> 4
	// 2 3 0 1 -> 4
	// 3 2 1 0 -> 4
	// 4 5 6 7 -> 0

	// k = 4
	// 0 1 2 3 4 -> 5
	// 1 0 3 2 5 -> 4
	// 2 3 0 1 6 -> 4
	// 3 2 1 0 7 -> 4
	// 4 5 6 7 0 -> 1

	// 0 1 2 3 4 5 -> 6
	// 1 0 3 2 5 4 -> 6
	// 2 3 0 1 6 7 -> 4
	// 3 2 1 0 7 6 -> 4
	// 4 5 6 7 0 1 -> 2
	// 5 4 7 6 1 0 -> 2

	// 0 1 2 3 4 5 6 7 8   9 -> 10
	// 1 0 3 2 5 4 7 6 9   8 -> 10
	// 2 3 0 1 6 7 4 5 10 11 -> 8
	// 3 2 1 0 7 6 5 4 11 10 -> 8
	// 4 5 6 7 0 1 2 3 12 13 -> 8

	// 0 1 2 3 4 5 6 7  8  9 10 12 14 16 18 20 24 26 28 30 32 -> 11
	// 1 0 3 2 5 4 7 6  9  8 11 13 15 17 19 21 25 27 29 31 33 -> 10
	// 2 3 0 1 6 7 4 5 10 11  8  							  -> 9
	// 3 2 1 0 7 6 5 4 11 10  9 15 13 19 17 				  -> 8

	/*
		if i <= k and i doesnt exist in set, the output is 0.
		else
			k == 0 -> current MEX.
			k != 0
				current MEX 
	*/

	// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

	// 0 1 2 3 4 5 6 -> 7
	// 1 0 3 2 5 4 7 -> 6
	// 2 3 0 1 6 7 4 -> 5
	// 3 2 1 0 7 6 5 -> 4
	// 4 5 6 7 0 1 2 -> 3
	// 5 4 7 6 1 0 3 -> 2
	// 6 ...		 -> 1
	// 7 ...		 -> 0

	// 0 -> mex : 1, k = 0 -> 1

	// 0 1
	// 1 0 -> mex: 2, k = 1 ->  2

	// 0 1 -> mex: 2, k = 0 -> 2

}

void solve() {
	int q, k;
	cin >> q >> k;

	Mex m(MAX_N);

	while (q--) {
		int x;
		cin >> x;

		m.update(x);

		int mex = INT_MAX;
		for (int i = 0; i <= k; ++i) {
			for (auto e : m.getAvailable()) {
				cout << (e ^ i) << ' ';
			}
			cout << '\n';
		}

		 mex = m.mex();

		if (mex <= k) {
			cout << 0 << '\n';
		} else {
			
		}
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
    