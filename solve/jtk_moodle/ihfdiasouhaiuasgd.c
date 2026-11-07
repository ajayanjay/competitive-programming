/* File			: OSN SEQUENCE (FINAL BOSS RAHHH)*/
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char input[500];
	int last;
	
/* Program */
	scanf("%[^\n]%*c", input);
	
	last = 0;	
	
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 'O' || input[i] == 'S' || input[i] == 'N') {
			if (input[i] != input[last - 1]) {
				input[last] = input[i];
				last++;
			}
		}
	}
	
	for (int i = 0; i < last; i++) {
		printf("%c", input[i]);
	}

    return 0;
}
