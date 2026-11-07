#include <limits.h>
#include <stdio.h>

#define ll long long
#define ull unsigned long long

#define MAX 1000000000000000000

ull getSum(ull n) {
	if (n > 2000000) return ULLONG_MAX;
	return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

ull func(ull x) {
	ull left = 1;
	ull right = x;

	ull answer;

	while (left <= right) {
		ull mid = (left + right) / 2;
		if (getSum(mid) >= x) {
			answer = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	ull answer_sum = getSum(answer);

	if (answer_sum == x) {
		return answer * (answer + 1) / 2;
	}

	// answer_sum > x

	ull answer_temp = answer - 1;
	ull sum_temp = getSum(answer_temp);

	ull remaining = x - sum_temp;

	ull divised = (remaining + answer - 1) / answer;

	answer_temp = answer_temp * (answer_temp + 1) / 2;

	return answer_temp + divised;
}

int main(void) {

	int t;
	int index = 0;

	scanf("%d", &t);

	ull answers[t];

	while (t--) {
		ull x;
		scanf("%llu", &x);

		ull count = func(x);
		answers[index++] = count;
	}

	for (int i = 0; i < index; ++i) {
		printf("%llu\n", answers[i]);
	}

	return 0;
}