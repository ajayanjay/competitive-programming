/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <string.h>
#include <stdio.h>

int main() {

/* Kamus */
	//const char kamus[7] = {'A', 'D', 'O', 'P', 'Q', 'R'};
	
	int kamus[100] = {0};
	kamus['A'] = 1;
	kamus['B'] = 2;
	kamus['D'] = 1;
	kamus['O'] = 1;
	kamus['P'] = 1;
	kamus['Q'] = 1;
	kamus['R'] = 1;
	
	char input[50], current;
	int count = 0, len;

/* Program */
	scanf("%s", input);
	
	len = strlen(input);
	
	for (int i = 0 ; i < len; ++i) {
		
		count += kamus[input[i]];
		
		/*
		for (int j = 0 ; j < 7; j++) {
			if (kamus[j] == current) {
			++count;
			break;
			}
		}
		*/
		
	}
	
	printf("%d", count);

    return 0;
}
