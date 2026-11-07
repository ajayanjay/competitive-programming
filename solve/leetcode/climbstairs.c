#include <stdio.h>

int memo[10000] = {0};

int climbStairs(int n) {
	if (n <= 3) {
		return n;
	}   
	
	if (memo[n] != 0) {
		return memo[n];
	} else {
		memo[n] = climbStairs(n - 2) + climbStairs(n - 1);
		return memo[n];
	}
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	printf("%d", climbStairs(n));
	
}