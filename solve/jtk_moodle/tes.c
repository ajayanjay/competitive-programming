/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char lib[7] = "ABDOPQR";
	int jumlahlubang[7] = {1,2,1,1,1,1,1};
	char input[51];
	int count = 0;
	int length;

/* Program */

	fgets(input, 51, stdin);
	
	length = strlen(input);
	
	for (int i = 0; i < length; i++) {
		
		for (int j = 0; j < 7; j++) {
			if (input[i] == lib[j]) {
				count += jumlahlubang[j];
				break;
			}
		}
		
	}
	
	printf("%d", count);

/*
AaBbDdegoOpPqQR
*/
    return 0;
}
