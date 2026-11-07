/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int kpk (int, int);
int fpb (int, int);

/* KPK (a,b) = a*b / FPB(a,b) */
int kpk(int a, int b) {
	return (a * b) / fpb(a, b);
}

/* FPB (a,b) = GCD (a,b) */
int fpb(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int main() {

/* Kamus */
	int a, b, c;

/* Program */
	scanf("%d %d %d", &a, &b, &c);
	
	printf("%d", kpk(a, kpk(b, c)));

    return 0;
}
