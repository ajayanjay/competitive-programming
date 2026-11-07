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

bool isVocal(char c) {
	return (c == 'a') ||
	(c == 'i') || 
	(c == 'u') || 
	(c == 'e') ||
	(c == 'o');
}

bool solve() {
    string s;
    cin >> s;

    int i = 0;
    int len = s.size();

    while (i < len) {
    	char c = s[i];

    	if (!isVocal(c)) {
    		++i;
    		continue;
    	}

    	++i;
    	if (i >= len) return false;

    	char g = s[i];
    	if (g != 'g') return false;

    	++i;
    	if (i >= len) return false;

    	char n = s[i];
    	if (n != c) return false;

    	++i;
    }

    return true;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "Begenagar\n";
        else cout << "Sagalagah\n";
    }
    return 0;
}
    