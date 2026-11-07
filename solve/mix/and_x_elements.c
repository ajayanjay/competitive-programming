#include <stdio.h>

#define ll long long

int main(void) {

	int t;
	scanf("%d", &t);

	while (t--) {
		ll n, x;
		ll v = 0;

		scanf("%lld %lld", &n, &x);

		ll a[n];
		for (ll i = 0; i < n; ++i) {
			scanf(" %lld", &a[i]);
		}

		for (ll i = x; i < n; ++i) {
			v |= a[i];
		}

		printf("%lld\n", v);
	}

	return 0;
}