#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int main(void) {

	ll t;
	scanf("%lld", &t);

	while (t--) {
		ll l, r;

		scanf("%lld %lld", &l, &r);

		if (l == r) {
			printf("%lld\n", r);
			continue;
		}

		ll gap = r - l;

		ll num1 = gap - 1;

		ll num2 = gcd(l, r);

		ll num3 = r;

		ll result = num1 + num2 + num3;

		printf("%lld\n", result);
	}

	return 0;
}