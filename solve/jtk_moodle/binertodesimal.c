/* File			: binertodesimal.c */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

/* Kamus */
	char biner[20];
	int desimal, len;

/* Program */
	scanf("%[^\n]%*c", biner);
	desimal = 0;
	
	len = strlen(biner);
	
	for (int i = 0; i < len; i++) {
		desimal += (biner[len - i - 1] - '0') * pow(2, i);
	}
	
	printf("%d", desimal);

    return 0;
}
