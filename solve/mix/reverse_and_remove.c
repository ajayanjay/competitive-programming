#include <stdio.h>
#include <stdbool.h>

#define ll long long

int main(void) {

	ll n, k;

	scanf("%lld %lld", &n, &k);

	ll a[n];
	for (ll i = 0; i < n ; ++i)
		scanf(" %lld", &a[i]);

	ll num_removed = k / 2;
	ll remaining = k % 2;

	ll first = 0 + num_removed + remaining;
	ll last = n - num_removed;

	bool reversed = remaining == 1;

	if (reversed) {
		for (ll i = last - 1; i >= first; --i) {
			printf("%lld ", a[i]);
		}
	} else {
		for (ll i = first; i < last; ++i) {
			printf("%lld ", a[i]);
		}
	}

	return 0;
}