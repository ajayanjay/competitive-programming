/* File			: SelisihPRIME.c */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main() {

/* Kamus */
    int x, y;

/* Program */
    scanf("%d %d", &x, &y);

    while (x < y) if (isPrime(x++)) break; --x;

    while (x < y) if (isPrime(y--)) break; ++y;

    printf("%d", (y - x));
    return 0;
}

bool isPrime(int a) {
    for (int i = 2; i*i <= a; ++i)
        if (a % i == 0) return false;
    return true;
}
