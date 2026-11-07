#include <stdio.h>

int main(void) {
	unsigned long long a;
	unsigned long long b;
	scanf("%llu %llu", &a, &b);

	unsigned long long max = a > b ? a : b;
	unsigned long long min = a >= b ? b : a;


	unsigned long long temp = 1;
	for (unsigned long long i = 2; i <= min; ++i) {
		temp *= i;
	}

	printf("%llu", temp);

	return 0;
}