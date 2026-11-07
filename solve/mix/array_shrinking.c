#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int solve(int *arr, int size) {
	int min = INT_MAX;
	bool has_pair = false;

	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] == arr[i + 1]) {
			has_pair = true;

			// create copy
			int new_size = size - 1;
			int new_arr[new_size];

			int i2 = 0;
			for (int j = 0; j < new_size; ++j) {
				
				if (i == j) {
					new_arr[j] = arr[i2] + 1;
					i2 += 2;
					continue;
				}

				new_arr[j] = arr[i2];
				i2++;
			}

			int local_min = solve(new_arr, size - 1);
			if (local_min < min) 
				min = local_min;
		}
	}
 
	if (!has_pair)
		return size;
	else
		return min;
}

int main(void) {

	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf(" %d", &arr[i]);

	int min = solve(arr, n);

	printf("%d", min);

	return 0;
}