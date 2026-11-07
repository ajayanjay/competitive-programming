/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	int lib[90];
	lib['I'] = 1;
	lib['V'] = 5;
	lib['X'] = 10;
	lib['L'] = 50;
	lib['C'] = 100;
	lib['D'] = 500;
	lib['M'] = 1000;
	
	char input[15];
	int desimal, len;
	
/* Program */
	scanf("%[^\n]%*c", input);
	
	len = strlen(input);
	desimal = 0;
	
	for (int i = 0; i < len - 1; i++) {
		if (lib[input[i]] < lib[input[i + 1]]) {
			desimal -= lib[input[i]];
		} else {
			desimal += lib[input[i]];
		}
	}
	
	desimal += lib[input[len - 1]];
	
	printf("%d", desimal);

    return 0;
}
