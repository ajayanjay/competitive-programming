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

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();

    if (m > n) return "";

    int minL = -1, minR = -1;
    int minDist = INT_MAX;

    vector<int> req(128, -1);
    int unq = 0;
    for (auto c : t) {
        if (req[c] == -1) {
        	++unq;
        	req[c] = 0;
        }

        ++req[c];
    }

    vector<int> lib(128, 0);

    int l = 0, r = 0;
    // first iter, r goes right until unique is 0
    for (; r < n; ++r) {
        char c = s[r];

        if (req[c] == -1) continue;

        ++lib[c];
        if (lib[c] == req[c]) --unq;

        if (unq == 0) {
            minR = r;
            break;
        }
    }

    if (unq != 0) {
    	return "";
    }

    // second iter, l goes right until find first req.
    for (; l <= (n - m); ++l) {
    	char c = s[l];
    	if (req[c] == -1) continue;

    	if (lib[c] == req[c]) break;

    	--lib[c];
    }

    minL = l;
    minDist = minR - minL + 1;

    // a switchback
    while (minDist > m) {

        // r goes right until r finds the char at l. 
        while (r < n - 1) {
        	++r;
            char c = s[r];
 
            if (req[c] == -1) continue; // skip if not part of t.

            ++lib[c]; // add to saved character.
            break;
        }

        // l goes right until l finds a char that cannot be removed.
        for (; l < (n - m); ++l) {
            char c = s[l];

            if (req[c] == -1) continue; // skip if not part of t.

            if (lib[c] == req[c]) break; // stop looping since there isnt any replacement.

            --lib[c]; // remove from saved character
        }

        // cout << l << ' ' << s[l] << " - " << r << ' ' << s[r] << '\n';

        int dist = abs(r - l + 1);
        if (dist < minDist) {
            minL = l;
            minR = r;
            minDist = dist;
        }

        if (minDist == m) break;
        if (r >= n - 1 || l >= (n - m)) break;
    }

    // cout << minL << ' ' << minR << ' ' << minDist << '\n';

    return s.substr(minL, minDist);
    
}

void solve() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
}

int main() {
    // fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();

        // if (solve()) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}
    