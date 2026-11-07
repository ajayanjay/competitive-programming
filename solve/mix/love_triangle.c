#include <stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);

	int plane[n];
	for (int i = 0; i < n; ++i) {
		scanf(" %d", &plane[i]);
	}

	for (int i = 0; i < n; ++i) {
		int next_index = plane[i] - 1;;
		int next_next_index = plane[next_index] - 1; 
		int next_next_next_index = plane[next_next_index] - 1;

		if (plane[i] == plane[next_next_next_index]) {
			printf("YES");
			return 0;
		}

	}

	printf("NO");
	return 0;

}