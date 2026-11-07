/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int a[3][3], b[3][3];

/* Program */
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d", &a[i][j]);
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d", &b[i][j]);
			a[i][j] += b[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
