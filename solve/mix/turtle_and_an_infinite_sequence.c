#include <limits.h>
#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);


	long long answers[t];
	int answer_index = 0;
	while (t--) {
		long long n, m;
		scanf("%lld %lld", &n, &m);

		if (m != 0) {
			long long left = n - m;
			if (left < 0) left = 0;

			long long right = n + m;

			for (long long i = left + 1; i < n; ++i) {
				left |= i;
			}

			for (long long i = right - 1; i > n; --i) {
				right |= i;
			}

			n = left | n | right;
		}

		answers[answer_index++] = n;
	}

	for (int i = 0; i < answer_index; ++i) {
		printf("%lld\n", answers[i]);
	}

	return 0;
}