/* File			: konversi desimal ke biner */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
    int a, i, biner[31];

/* Program */
    scanf("%d", &a);
    i = 0;

    while (a != 0) {
        biner[i] = (a % 2);
        a /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", biner[j]);
    }

    return 0;
}
