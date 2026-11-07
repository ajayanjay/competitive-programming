/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

void example(int value, int *address);

int main() {

/* Kamus */
	int a, b;

/* Program */
	
	scanf("%d %d", &a, &b);
	
	example(a, &b);
	
	printf("%d %d", a, b);

    return 0;
}

void example(int value, int *address) {
	
	value = 1 + 9;
	*address = 20 + 5;
	
	// value = 10
	// address = 25
}
