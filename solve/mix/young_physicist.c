#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int x[n], y[n], z[n];

	int sum = 0;
	for (int i = 0; i < n; ++i){

		scanf("%d %d %d", &x[i], &y[i], &z[i]);

		sum += x[i] + y[i] + z[i];
	}


	if (sum == 0) {
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}