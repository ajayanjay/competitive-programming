#include <stdio.h>
#include <stdbool.h>

#define ll long long

int main(void) {

	int t;
	int index = 0;

	scanf("%d", &t);

	bool answers[t];

	while (t--) {
		ll x1, y1;
		ll x2, y2;

		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

		x1 = (x1 < 0) ? -(x1) : x1;
		y1 = (y1 < 0) ? -(y1) : y1;

		x2 = (x2 < 0) ? -(x2) : x2;
		y2 = (y2 < 0) ? -(y2) : y2;

		if ((x1 % 2 == x2 % 2) && (y1 % 2 == y2 % 2)) {
			answers[index++] = true;
		} else {
			answers[index++] = false;
		}
	}

	for (ll i = 0; i < index; ++i)
		if (answers[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	return 0;
}
// 13 42  32 420
// 1 0 0 1