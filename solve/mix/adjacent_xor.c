#include <stdio.h>
#include <stdbool.h>

#define ll long long

int main(void) {

	int t;
	scanf("%d", &t);

	while (t--) {
		ll n;
		scanf("%lld", &n);

		ll a[n], b[n];

		for (ll i = 0; i < n; ++i)
			scanf(" %lld", &a[i]);		

		for (ll i = 0; i < n; ++i)
			scanf(" %lld", &b[i]);

		if (a[n - 1] != b[n - 1]) {
			printf("no\n");
			continue;
		}

		bool result = true;

		for (ll i = 0; i < n - 1; i++) {

			if (a[i] == b[i] || (a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i])
				continue;
			else {
				result = false;
				break;
			}

			if (a[i] == b[i]) {
				i++;
			}
			else if (i + 1 < n && (a[i] ^ a[i + 1]) == b[i]) {
				i++;
			} else {
				// a[i] xor a[i + 1] != b[i], modify a[i + 1] in such way that would make this true

				int j = i + 1;

				while (j < n - 1 && (a[j] ^ a[j + 1]) != b[j]) {
					j++;
				}

				if (j >= n - 1) {
					result = false;
					break;
				} else {

					int new_i = j;
					// backtrack
					while (i <= j) {
						a[j] ^= a[j + 1];
						if (a[j] != b[j]) {
							result = false;
							break;
						}
						--j;	
					}


					i = new_i + 1;
				}
			}
			if (!result) break;
		}

		if (result) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}

	return 0;
}