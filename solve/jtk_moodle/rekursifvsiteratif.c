/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int sum(int n) {
	if (n == 1) return 1;
	else return n + sum(n-1);
}

int main() {

/* Kamus */
	int n, sums;

/* Program */

	n = 10000;

//	sums = sum(n);

	for (int i = 1; i <= n; ++i) {
		sums += i;
	}

    return 0;
}
