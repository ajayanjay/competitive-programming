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

bool isTwinPrime(int a, int b) {
	if (a == 1 || b == 1) return false;
	if (a % 2 == 0 || b % 2 == 0) return false;

	for (int i = 3; ; i += 2) {
		bool t = false;
		if (i * i <= a) {
			if (a % i == 0) return false;	
		} else t = true;

		if (i * i <= b) {
			if (b % i == 0) return false;	
		} else if (t) break;
	}

	return true;
}

bool solve() {
    int a, b;
    cin >> a >> b;

    int mn = min(a, b);
    int mx = max(a, b);

    if (mn + 2 != mx) return false;

    return isTwinPrime(a, b);
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        if (solve()) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
    