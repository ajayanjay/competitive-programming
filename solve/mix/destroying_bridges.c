#include <stdio.h>

int main(void) {

	int t;
	scanf("%d", &t);

	int answers[t];
	for (int i = 0; i < t; ++i) {

		int n, k;
		scanf("%d %d", &n, &k);

		if (k >= n - 1)
			answers[i] = 1;
		else
			answers[i] = n;

	}

	for (int i = 0; i < t; ++i) 
		printf("%d\n", answers[i]);

	return 0;
}