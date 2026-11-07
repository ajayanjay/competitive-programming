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
	int b, i, r;
};

void solve() {
    int n;
    cin >> n;

    vi beauty(n), intellect(n), richness(n);

    for (auto & e : beauty)
    	cin >> e;
    for (auto & e : intellect)
    	cin >> e;
    for (auto & e : richness)
    	cin >> e;

    if (n == 1) {
    	cout << 0;
    	return;
    }

   	

    /*
		for i 1..N
			for j 1..N
				all(i) < all(j) 
					++cnt
                    break

        j != i && beauty[j] > beauty[i] && intellect[j] > intellect[i] && richness[j] > richness[i]
        ========================
        sort all according to beauty
        for i 1..N
            for j (i + 1)..N
                all(i) < all(j)
                    ++cnt
                    break

        j > i && intellect[j] > intellect[i] && richness[j] > richness[i]
        
    */


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
    