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

#define MAXN 1000000

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vi p = manacher(s);

    int mx = 0;
    int idx = 0;
    for (int i = 0; i < p.size(); ++i) {
    	if (p[i] > mx) {
    		mx = p[i];
    		idx = i;
    	}
    }

    int l, r;
   	if (idx % 2 == 0) { // odd-length palindrome
   		idx /= 2;
   		mx = (mx / 2) - 1;

   		l = idx - mx;
   		r = idx + mx;
   	} else { // even-length palindrome
   		idx /= 2;
   		mx /= 2;

   		l = idx - (mx - 1);
   		r = idx + mx;
   		
   	}

   	cout << s.substr(l, r - l + 1);

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
