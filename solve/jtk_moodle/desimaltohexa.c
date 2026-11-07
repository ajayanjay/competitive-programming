/* File			: desimal hexadesimal*/
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int desimal, i;
	char hexadecimal[32];

/* Program */
	char lib[16] = {'0' ,'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	scanf("%d", &desimal);
	
	i = 0;
	while (desimal != 0) {
		hexadecimal[i] = lib[desimal % 16];
		desimal /= 16;
		i++;
	}
	
	for (int j = i -1; j >= 0; j--) {
		printf("%c", hexadecimal[j]);
	}
	
    return 0;
}
