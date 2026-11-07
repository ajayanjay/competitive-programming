#include <stdio.h>
#include <stdlib.h>

#define ll long long

typedef struct {
	ll demand;
	ll rate;

	ll c;
} _t;

int cmp(const void * a, const void * b) {
	return (((const _t *) a)->rate - ((const _t *)b)->rate);
}

int main(void) {


	ll t;
	scanf("%lld", &t);

	ll answers[t];
	ll index;

	while (t--) {
		ll n, money;

		ll c[n];

		_t d[n];

		ll sum_demand = 0;
		for (ll i = 0; i < n; ++i){
			scanf(" %lld", &(d[i].demand));
			sum_demand += d[i].demand;
			d[i].c = 0;
		}

		ll remaining = money - sum_demand;

		for (ll i = 0; i < n; ++i)
			scanf(" %lld", &(d[i].rate));

		if (remaining == 0) {
			answers[index++] = 0;
			continue;
		}

		qsort(d, n, sizeof(_t), cmp);

		
	}
}


// a1 -> aN: sum -> [28] -> remaining -> 5
// 2 2 3 3 7 8 (most efficient : 4 (2 2s))

// -> how can we distribute the remaining 5 efficiently to 