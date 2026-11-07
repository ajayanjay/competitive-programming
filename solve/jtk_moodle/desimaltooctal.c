/* File			: desimal hexadesimal*/
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int desimal, i;
	int octaldecimal[32];

/* Program */
	scanf("%d", &desimal);
	
	i = 0;
	while (desimal != 0) {
		octaldecimal[i] = desimal % 8;
		desimal /= 8;
		i++;
	}
	
	for (int j = i -1; j >= 0; j--) {
		printf("%d", octaldecimal[j]);
	}
	
    return 0;
}
