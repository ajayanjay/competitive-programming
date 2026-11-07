#include <stdio.h>

#define ll long long

int main(void) {

	int t;
	scanf("%d", &t);

	ll answers[t];

	for (int i = 0; i < t; ++i) {

		ll n;
		scanf("%lld", &n);
		char board[2][n];

		ll answer = 0;

		for (ll j = 0; j < n; ++j)
			scanf(" %c", &board[0][j]);
		for (ll j = 0; j < n ; ++j) {
			scanf(" %c", &board[1][j]);

			if (board[1][j] == '0') continue;

			if (board[0][j] == '0') {
				++answer;
			} else if (j > 0 && board[0][j - 1] == '1') {
				board[0][j - 1] = '0';
				++answer;
			} else if (j < n - 1 && board[0][j + 1] == '1') {
				board[0][j + 1] = '0';
				++answer;
			}
		}

		answers[i] = answer;


	}

	for (int i = 0; i < t; ++i)
		printf("%lld\n", answers[i]);

}