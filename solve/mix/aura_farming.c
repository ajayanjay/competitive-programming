#include <stdio.h>
#include <stdlib.h>

#define ll long long

typedef struct {
	ll aura_required;
	ll aura_gained;
} soal_t;

int cmp(const void * a, const void * b) {
	return ((const soal_t *) a)->aura_required - ((const soal_t *) b)->aura_required;
}

int main(void) {

	ll n, initial_aura;

	scanf("%lld %lld", &n, &initial_aura);

	soal_t soal[n];
	ll aura_debt = 0;

	for (ll i = 0; i < n; ++i) {
		scanf("%lld %lld", &soal[i].aura_required, &soal[i].aura_gained);
	}

	qsort(soal, n, sizeof(soal_t), cmp);

	for (ll i = 0; i < n; ++i) {
		if (soal[i].aura_required <= initial_aura)
			initial_aura += soal[i].aura_gained;
		else break;
	}

	printf("%lld", initial_aura);

	return 0;
}

/*
16	6
5	2
110	10
21	20
26	25

5
3 2
6 4
110 10
*/