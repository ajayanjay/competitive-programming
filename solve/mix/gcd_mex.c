#include <stdio.h>
#include <stdbool.h>

#define ll long long

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(void) {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		if (n == 1) {
			printf("1\n1\n");
			continue;
		} else if (n == 2) {
			printf("2\n1 2\n");
			continue;
		} else if (n == 3) {
			printf("3\n1 2 4\n");
			continue;
		}

		printf("%d\n", n);
		bool pass = false;
		int num;
		for (int i = 1; i <= n - 1; ++i) {
			printf("%d ", i);

			if (!pass && i * 2 > (n - 1)) {
				pass = true;
				num = i;
			}
		}

		// lcm(num to n - 1)
		ll big_num = 1;
		for (int i = num; i <= n - 1; ++i) {
			big_num = lcm(big_num, i);
		}

		printf("%lld\n", big_num);
	}
	return 0;
}

