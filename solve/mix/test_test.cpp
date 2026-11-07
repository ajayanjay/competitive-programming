#include <bits/stdc++.h>

#define ll long long

ll n, a, b;

using namespace std;

int main() {
    cin >> n >> a >> b;
    
    if (a != b) {
        cout << "NO" << endl;
        return 0;
    }
   
    if (n % 2 == 1 && !(n & 2))
        cout << "NO" << '\n';
    else
        cout << "YES" << endl;
 
    
    return 0;
}