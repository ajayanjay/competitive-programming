#include <stdio.h>

#define ll long long

int main(void) {

	int t;
	int index;

	scanf("%d", &t);

	ll answers[t];

	while (t--) {
		ll n;
		scanf("%lld", &n);

		ll p[n - 1], q[n - 1];
		for (ll i = 0; i < n - 1; ++i) {
			scanf("%lld %lld", &p[i], &q[i]);
		}

		
	}

	for (int i = 0; i < index; ++i) {
		printf("%lld\n", answers[i]);
	}

	return 0;
}