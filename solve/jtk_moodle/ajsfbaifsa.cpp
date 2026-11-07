/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char input[200];
	int count = 0;

/* Program */
	scanf("%[^\n]%*c", input);
	
	for (int i = 0; i <= strlen(input) / 2; i++) {
		
		if (input[i] == input[strlen(input) - i - 1]) {
			count++;
		}
	}
	
	printf("%d", count);

    return 0;
}
