#include <stdio.h>
#include <stdbool.h>

#define MAX 1001

bool can_win(char outcomes[MAX][MAX], int n, int current_fighter, int count) {

	if (count == n) {
		printf("Yes\n");
		return true;
	} 

	for (int opponent = current_fighter + 1; opponent < n; opponent++) {

		char outcome = outcomes[current_fighter][opponent];

		if (outcome == '1' || outcome == '?') {
			if (can_win(outcomes, n, opponent, count + 1)) {
				printf("%d %d\n", current_fighter + 1, opponent + 1);
				return true;
			} else {
				return false;
			}
		}
	}


	return false;
}

int main(void) {

	int t;
	scanf("%d", &t);

	char outcomes[MAX][MAX];

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) {
			scanf("%s", outcomes[i]);
		}

		if (!can_win(outcomes, n, 0, 1)) {
			printf("No\n");
		}

		printf("\n");		
	}


	return 0;
}