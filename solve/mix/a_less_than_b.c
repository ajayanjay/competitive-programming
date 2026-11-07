#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ll long long

void strrvrs(char* str, int l, int r) {
	while (l < r) {

		char temp = str[l];
		str[l] = str[r];
		str[r] = temp;

		l++;
		r--;
	}
}

int myStrcmp(char *a, char *b) {
	int count = 0;
	while (*a != 0 && *b != 0) {
		if (*a > *b) {
			return count;
		} else if (*a < *b) {
			return -count;
		}
		a++;
		b++;
		count++;
	}

	if (*a != 0) {
		return count;
	} else if (*b != 0) {
		return -count;
	} else return 0;
}

int main(void) {

	ll t;
	scanf("%lld", &t);

	while (t--) {
		ll n;
		scanf("%lld", &n);

		char a[n], b[n];
		scanf("%s", a);
		scanf("%s", b);

		int result = myStrcmp(a, b);
		
		if (result < 0) {
			printf("Yes\n");
			continue;
		}

		// strcmp >= 0

		bool valid = false;
		char current = b[result];
		int index = 0;
		for (int i = result + 1; i < n; ++i) {
			if (current > a[i]) {
				printf("Yes\n");
				valid = true;
				break;
			} else if (current == a[i]) {

				int left_index = result + 1;
				int right_index = i - 1;
				
				while (left_index <= i && right_index >= result) {
					char mustLow = a[right_index];
					char mustHigh = b[left_index];

					if (mustHigh > mustLow) {
						printf("Yes\n");
						valid = true;
						break;
					} else if (mustHigh < mustLow) {
						break;
					}

					left_index++;
					right_index--;
				}

				if (valid) break;
			}
		}

		if (!valid)
			printf("No\n");
	}

	return 0;
}

/// abza
/// aaza

// acza
// abza

// abza
// aaza

// bczb
// bbzb

// if a[i] > b[i] we dont need to find for replacement.
// if a[i] == b[i] we are fine, but should find for replacement.
// if a[i] < b[i] we are in danger zone, we HAVE to find replacement.