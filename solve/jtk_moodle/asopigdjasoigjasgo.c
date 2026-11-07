/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int a, b, count;

/* Program */
	scanf("%d %d", &a, &b);
	
	int x[a], y[b];
	
	for (int i = 0; i < a; i++) {
		scanf("%d", &x[i]);
	}
	
	count = 0;
	for (int i = 0; i < b; i++) {
		scanf("%d", &y[i]);
		
		for (int j = 0; j < a; j++) {
			if (y[i] < x[j]) {
				++count;
			}
		}
		
	}
	
	printf("%d", count);

    return 0;
}
