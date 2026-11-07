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

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

   	vi prefSum(n);

   	// for (auto e : prefSum)
   	// 	cout << e << ' ';
   	// cout << '\n';

   	// i < j
   	// sum[i..j] == i - j + 1
   	// P[j] - P[i - 1] = (j) - (i - 1)
   	// P[j] - (j) = P[i - 1] - (i - 1), for all i <= j

   	prefSum[0] = s[0] - '0';
   	for (int i = 1; i < n; ++i)
   		prefSum[i] = prefSum[i - 1] + (s[i] - '0'); 

   	unordered_map<int, int> m;
   	// P[0] - 0 = P[-1] - (-1)
   	// P[0] = 0 + 1
   	m[1] = 1;
   	ull cnt = 0;
   	for (int i = 0; i < n; ++i) {
   		int val = prefSum[i] - i;

   		cnt += m[val];
   		m[val]++;
   	}



   	// -> query (i) -> count of i < j whose sum[i..j] == i - j + 1
   	// possibly fenwick point update
   	// update(i, x) do something... that makes query possible

   	// ull cnt = 0;
   	// for (int i = 0; i < n; ++i) {
   	// 	int bef = i == 0 ? 0 : prefSum[i - 1];
   	// 	for (int j = i; j < n; ++j) {
   	// 		int sum = prefSum[j] - bef;
   	// 		if (sum == j - i + 1)
   	// 			++cnt;
   	// 	}
   	// }

   	// 1 2 0
   	// 1 3 3
   	// 1 1 0 1 1
   	// 1 2 2 3 4
   	// 1 - 1 - prev

   	cout << cnt << '\n';
   	
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
    