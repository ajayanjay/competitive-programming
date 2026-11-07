#include <stdio.h>

#define ll long long

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		int r[n];
		ll cookies = 0;
		int temp = 1;
		for (int i = 0; i < n; ++i) {
			scanf(" %d", &r[i]);
			if (i != 0) {
				if ((r[i] > r[i - 1])) {
					temp += 1;
				} else {
					temp = 1;
				}
			}
			cookies += temp;
		}

		printf("%lld\n", cookies);

	}

	return 0;
}