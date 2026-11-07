#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long MOD = 1000000007) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

double myPow(double x, long long n) {

    double res = 1;
    bool dv = n < 0;
    if (dv) n = -n;

    while (n > 0) {
        if (n % 2 == 1) {
            if (dv)
                res /= x;
            else
                res *= x;
        }
        x *= x;
        n >>= 1;
    }   
    return res;
}