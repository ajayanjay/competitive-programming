/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

/* Kamus */
	char a[3][3], currentchar;
	char lib[5] = "aiueo";
	bool found;

/* Program */

	found = false;
	
	for (int i = 0 ; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %c", &a[i][j]);
			
			currentchar = a[i][j];
			
			a[i][j] = tolower(currentchar);
			
			for (int k = 0; k < 5; k++) {
				if (a[i][j] == lib[k]) {
					printf("%c: (%d,%d)\n", currentchar, (i+1), (j+1));
					found = true;
				}
			}
			
		}
	}
	
	if (!found) {
		printf("tidak ada huruf vokal");
	}

    return 0;
}
