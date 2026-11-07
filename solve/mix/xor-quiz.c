#include <stdio.h>
#include <math.h>


int xor(int a, int b) {
	return a ^ b;
}

int gcd(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}

	return a;
}


int main (void ) {
	int c, n;

	scanf("%d %d", &c, &n);

	int maxQuestion = ceil(0.65 * c);
	int q[maxQuestion];

	


	return 0;
}

int operator() {

	// operator has n possible answer.
	int n;
	int a[n];

	// we have q amount of question.
	int q;
	scanf("%d", &q);

	// every single element.
	int x[q];
	for (int i = 0; i < q; ++i)
		scanf(" %d", &x[i]);
	

	// they then iterate through their array like this

	for (int i = 0; i < q; ++i) {

		int sum = 0;
		for (int j = 0; j < n; ++j) {

			// bitwise xor sum for every possible y such that y is coprime to x/
			if (gcd(a[j], x[i]) == 1) { 
				sum += xor(a[j], x[i]); 
			}

		}

		// they then "input" them
		printf("%d ", sum);
	}

	return 0;
}

