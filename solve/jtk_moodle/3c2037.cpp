/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int x[4][4], count;

/* Program */
	count = 0;
	
	for (int i= 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf(" %d", &x[i][j]);
			if (x[i][j] % 2 == 1) {
				count++;
			}
		}
	}
	
	printf("%d", count);
	
    return 0;
}
