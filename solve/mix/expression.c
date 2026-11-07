#include <limits.h>
#include <stdio.h>

int main(void) {

	int a[3];

	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	int max = INT_MIN;

	for (int i = 0; i < 3; ++i) {

		int curr;
		for (int j = 0; j < 2; ++j) {

			if (j == 0) {
				curr = a[i] + a[ (i + 1) % 3] ;
			} else {
				curr = a[i] * a[ (i + 1) % 3] ;
			}

			for (int k = 0; k < 2; ++k) {

				int temp;
				if (k == 0) {
					temp = curr + a[(i + 2) % 3];
				} else {
					temp = curr * a[(i + 2) % 3];
				}

				if (temp > max)
					max = temp;
			
			}

		}

	}

	printf("%d", max);

	return 0;
}