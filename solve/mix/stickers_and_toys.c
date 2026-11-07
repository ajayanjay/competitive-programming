#include <stdio.h>

#define ull unsigned long long

int main(void) {

	ull t;
	scanf("%llu", &t);

	ull answers[t];

	ull i = 0;

	while (t--) {
		ull n, s, t;

		scanf("%llu %llu %llu", &n, &s, &t);

		ull jumlah_universal = s + t; // 12
		ull jumlah_box = n; // 10

		ull sisa_box = jumlah_universal - jumlah_box; // 2

		ull pasti_celana = s - sisa_box; // 5
		ull pasti_baju = t - sisa_box; // 3

		ull max = pasti_celana > pasti_baju ? pasti_celana : pasti_baju; // 5

		answers[i++] = max + 1;

	}

	for (ull j = 0; j < i; ++j) 
		printf("%llu\n", answers[j]);

	return 0;
}