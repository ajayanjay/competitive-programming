#include <stdio.h>

#define ll long long

ll lud(ll x, ll y) {
	if (y % x == 0) return -1;



	return -1;
}

ll find_smallest_mult(ll x) {

	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0)
			return i;
	}

	return x;
}

int main(void) {

	ll n, x;

	scanf("%lld %lld", &n, &x);

	ll a[n];
	for (ll i = 0 ; i < n; ++i) {
		scanf(" %lld", &a[i]);
		a[i] = find_smallest_mult(a[i]);
	}
		
	for (ll i = 0; i < n; ++i) 
		printf("%lld\n", lud(x, a[i]));

	return 0;
}