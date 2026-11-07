

#include <limits.h>
#include <stdio.h>

#define abs(x) ((x < 0) ? (-x) : (x))

int main(void) {
	int N;
	long X;

	scanf("%d %ld", &N, &X);

	long A[N];

	for (int i = 0; i < N; ++i)
		scanf(" %ld", &A[i]);

	long min = LONG_MAX;
	long temp;

	for (int i = 0; i < N; ++i) {
		int diff = abs(A[i] - X);

		if (diff < min) {
			min = diff;
			temp = A[i];
		} else if (diff == min) {
			if (temp > A[i]) {
				temp = A[i];
			}
		}
	}

	printf("%ld", temp);

	return 0;
}