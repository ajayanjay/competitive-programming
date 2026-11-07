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

bool isupperstr(string &s) {
	return std::all_of(s.begin(), s.end(), [](unsigned char c){
        // We cast to unsigned char to avoid potential undefined behavior with negative char values
        return std::isupper(c) || std::isdigit(c) || std::ispunct(c) || std::isspace(c);
    });
}

std::vector<std::string> splitstr(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str); // Create an input string stream from the string

    while (std::getline(tokenStream, token, delimiter)) { // Extract tokens separated by the delimiter
        tokens.push_back(token);
    }
    return tokens;
}

void strip(std::string& str) {
    if (str.empty()) {
        return;
    }

    // Find the first non-whitespace character from the beginning
    auto first_char = str.begin();
    while (first_char != str.end() && std::isspace(*first_char)) {
        ++first_char;
    }

    // Find the last non-whitespace character from the end
    auto last_char = str.rbegin();
    while (last_char != str.rend() && std::isspace(*last_char)) {
        ++last_char;
    }

    // Construct the new string based on the found positions
    // base() converts a reverse iterator to a forward iterator pointing to the same element
    str = std::string(first_char, last_char.base());
}

std::string rstripstr(const std::string& str, const std::string& chars_to_remove) {
    size_t end = str.length();
    while (end > 0 && chars_to_remove.find(str[end - 1]) != std::string::npos) {
        end--;
    }
    return str.substr(0, end);
}

vector<string> hmm(string s) {
	vector<string> a = splitstr(rstripstr(s, ")"), '.');

	vector<string> n;
	for (auto e : a) {
		strip(e);
		n.push_back(e);
	}

	return n;
}

pair<unordered_map<string, string>, string> unification(string t1, string t2, unordered_map<string, string> subs) {
	
	if (t1 == t2)
		return {subs, ""};

	if (subs.find(t1) != end(subs))
		return unification(subs[t1], t2, subs);
	if (subs.find(t2) != end(subs))
		return unification(t1, subs[t2], subs);


	if (isupperstr(t1) && t1.size() == 1) {
		if (t2.find(t1) != string::npos)
			return {{}, "Gagal Unifikasi: Occurs Check (Variable muncul dalam term yang disubstitusikan)."};

		if (t1 != t2)
			subs[t1] = t2;

		return {subs, ""};
	}

	if (isupperstr(t2) && t2.size() == 1) {
		if (t1.find(t2) != string::npos)
			return {{}, "Gagal Unifikasi: Occurs Check (Variable muncul dalam term yang disubstitusikan)."};

		if (t2 != t1)
			subs[t2] = t1;

		return {subs, ""};
	}

	if (!isupperstr(t1) && !isupperstr(t2) && t1 != t2)
		if (!(t1.find("(") != string::npos) && !(t2.find("(") != string::npos))
			return {{}, "Gagal Unifikasi: Konstanta dasar berbeda"};
	
	if (t1.find("(") != string::npos && t2.find("(") != string::npos) {
		vector<string> vs1 = splitstr(t1, '(');
		vector<string> vs2 = splitstr(t1, '(');

		string n1 = vs1[0], args1_str = vs1[1];
		string n2 = vs2[0], args2_str = vs2[1];

		if (n1 != n2)
			return {{}, "Gagal Unifikasi Nama predikat / fungsi berbeda"};
		
		vector<string> args1, args2;
		try {
			args1 = hmm(args1_str);
			args2 = hmm(args2_str);
		} catch(exception e) {
			return {{}, "Gagal Unifikasi: kesalahan parsing argumen"};
		}

		if (args1.size() != args2.size())
			return {{}, "Gagal Unifikasi: Jumlah Argument berbeda"};

		for (int i = 0; i < args1.size(); ++i) {
			string a1 = args1[i];
			string a2 = args2[i];

			auto [result, str] = unification(a1, a2, subs);

			if (!str.empty()) {
				return {{}, str};
			}

			subs = result;
		}

		return {subs, ""};
	}

	return {{}, "Gagal Unifikasi: Struktur tidak cocok."};
}

void solve() {
    
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
