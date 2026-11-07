#include <stdio.h>
#include <stdbool.h>

#define ll long long

int main(void) {

	ll t;
	scanf("%lld", &t);

	while (t--) {
		ll n;
		scanf("%lld", &n);

		ll a[n];
		for (ll i = 0; i < n; ++i)
			scanf(" %lld", &a[i]);


		// 3 1 1 2 3 2 1
		// 3 
		ll i;
		printf("%lld ", a[0]);
		for (i = 0; i < n - 1;) {

			if (i + 2 >= n - 1 || a[i + 1] <= a[i + 2]) {
				// step
				printf("%lld ", a[i + 1]);
				++i;
			} else {
				// jump
				printf("%lld %lld %lld ", a[i + 2], a[i + 1], a[i + 3]);
				i += 3;
			}
		}
		
		printf("\n");


	}

	return 0;
}

/*
bool shouldStep, shouldJump;

			if (i + 2 >= n - 1 || a[i + 1] <= a[i + 2]) {
				// step
				printf("%lld %lld ", a[i], a[i + 1]);
				i += 2;
			} else {
				// jump
				printf("%lld %lld %lld ", a[i], a[i + 2], a[i + 1]);
				i += 3;
			}

			printf("\n");
			*/