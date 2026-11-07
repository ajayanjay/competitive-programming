#include <stdio.h>

#define ll long long 

int main(void) {
	int t;
	scanf("%d", &t);

	ll answers[t];

	int i = 0;

	while (t--) {

		ll a, b, c, r;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &r);

		ll left_bar = a > b ? b : a;
		ll right_bar = a > b ? a : b;

		ll left_circle = (c - r);
		ll right_circle = (c + r);

		ll initial_length = right_bar - left_bar;

		if (left_circle < left_bar) {
			left_circle = left_bar;
		}

		if (right_circle < left_bar) {
			right_circle = left_bar;
		}

		if (right_circle > right_bar) {
			right_circle = right_bar;
		}

		if (left_circle > right_bar) {
			left_circle = right_bar;
		}

		ll circle_length = right_circle - left_circle;
		ll final_length = initial_length - circle_length;

		answers[i++] = final_length;
	}

	for (int j = 0; j < i; ++j)
		printf("%lld\n", answers[j]);

	return 0;
}