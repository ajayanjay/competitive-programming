#include <stdio.h>

#define ll long long

int main(void) {
	ll initial_stone;
	scanf("%lld", &initial_stone);

	if (initial_stone % 3 == 1) {
		printf("Esteche");
	} else {
		printf("Yvens");
	}

	return 0;
}

/*
	l -> w, w -> l, w -> w, l -> w, w
	1 -> 2, 3 -> 4, 5 -> 6, 7 -> 8, 9 -> ...

	

*/