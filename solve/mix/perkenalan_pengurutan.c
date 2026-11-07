#include "stdio.h"

int main(void) {

	long n;
	scanf("%ld", &n);

	int a[n];

	for (long i = 0; i < n; ++i) {
		scanf("%d", &a[n]);
	}

	for (int i = 0; i < n; ++i) {
		printf(" %d", a[n]);
	}

	for (long i = 0; i < (n / 2); ++i) {
		long smallsub = i;
		for (long j = i + 1; j < n; ++j) {
			if (a[smallsub] > a[j])
				smallsub = j;
		}

		int temp = a[i];
		a[i] = a[smallsub];
		a[smallsub] = temp;
	}

	if (n % 2 == 0) {
		float median = ((float) a[n / 2] + (float) a[n / 2 - 1]) / 2;
		printf("%.1f", median);
	} else {
		printf("%.1f", (float) a[n/2]);
	}

}