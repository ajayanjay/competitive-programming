#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define int ll
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

	int sm = 0;
	vi a(n);
	for (auto &e: a) {
		cin >> e;
		sm += e;
	}
		

	// find mean, median, modus, SD, SR
	// finding modus would require a O(N Log N) on large memory anyway

	sort(all(a));

	// median
	double med;
	if (n % 2 == 0) {
		int mid = (n / 2);
		med = (a[mid - 1] + a[mid]) / 2;
	} else {
		int mid = n / 2;
		med = a[mid - 1];
	}

	// mean
	double avg = sm / n;

	// modus
	int modus = -1;
	int cnt = 0;
	int prev = -1;
	int maxCnt = -1;
	for (auto e : a) {
		if (prev == -1) {
			prev = e;
			cnt = 1;
			continue;
		} 

		if (prev == e) {
			++cnt;
		} else {			
			if (maxCnt < cnt) {
				maxCnt = cnt;
				modus = e;
			}
			cnt = 1;
		}
		prev = e;
	}

	// Mean Deviation, varians, standard deviation
	int x = 0, y = 0;
	for (auto e : a) {
		x += abs(e - avg);
		y += pow(e - avg, 2);
	}

	double SR = x / n;
	double varians = y / (n - 1);
	double SD = sqrt(varians);
	
	cout 	<< avg << ' ' << med << ' ' << modus << ' ' 
			<< SR << ' ' << varians << ' ' << SD << '\n';
}

signed main() {
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
    