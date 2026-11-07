/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char k1[10], k2[10];
	int N, difference, lena, lenb, max;

/* Program */
	
	scanf("%[^\n]%*c", k1);
	scanf("%[^\n]%*c", k2);
	
	lena = strlen(k1);
	lenb = strlen(k2);
	difference = 0;
	N = 0;
	
	if (lena > lenb) {
		max = lena;
	} else {
		max = lenb;
	}
	
	for (int i = 0; i < max; i++) {
		if (k1[i] != k2[i]) {
			difference = k1[i] - k2[i];
			N = i + 1;
			break;
		}
	}

	if (difference > 0) {
		printf("+%d\n", difference);
	} else {
		printf("%d\n", difference);
	}
	
	printf("%d", N);
	
    return 0;
}
