/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int fpb(int, int);

int main() {

/* Kamus */
	  int a, b, c;
	
	  scanf("%d %d %d", &a, &b, &c);

/* Program */
	  printf("%d", fpb(a, (fpb(b, c))));

    return 0;
}

// 20 10 5
// 20 * 5 
// 6  6

int fpb(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }

    return a;
}
