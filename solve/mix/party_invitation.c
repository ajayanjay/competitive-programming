#include <stdio.h>

int main (void) {

	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	
	int k;
	scanf("%d", &k);

	int index[k];
	for (int i = 0; i < k; ++i) {
		scanf("%d", &index[i]);

		int count = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] != -1) {
				++count;
				if (count == index[i]) {
					a[j] = -1;
					count = 0;
				}
			}
		}	
	}

	for (int i = 0; i < n; ++i)
		if (a[i] != -1)
			printf("%d\n", a[i]);

	return 0;
}