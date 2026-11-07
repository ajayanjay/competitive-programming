#include <bits/stdc++.h>
using namespace std;

// lpf[i] == i -> i is Prime.
// lpf[i] == x -> x is smallest prime factor of i
vector<int> leastPrimeFactor(int n) {

    vector<int> lpf(n + 1);
    for (int i = 0; i <= n; i++) {
        lpf[i] = i;
    }

    lpf[0] = 0;
    lpf[1] = 1; 
    
    for (int i = 2; i <= n; i++) {

        if (lpf[i] == i) {
            for (int j = i * 2; j <= n; j += i) {
                if (lpf[j] == j) {
                    lpf[j] = i;
                }
            }
        }
    }

    return lpf;
}

vector<bool> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}

vector<int> primes(vector<bool> &isPrime, int maxN) {
    vector<int> res;
    for (int i = 2; i <= maxN; ++i) {
        if (isPrime[i]) {
            res.pb(i);
        }
    }

    return res;
}

vector<pair<int,int>> factors(int x, vector<int> &primes) {

    vector<pair<int,int>> res;
    for (auto i : primes) {
        if (i * i > x) break;
        if (x % i == 0) {
            int num = i;

            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                ++cnt;
            }

            res.pb({num, cnt});
        }
        if (x <= 1) break;
    }

    if (x > 1) res.pb({x, 1});

    return res;
}