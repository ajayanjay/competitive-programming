/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

/* Kamus */
	char a[50];
	int i,j;
	
/* Program */
	scanf("%[^\n]%*c", a);
	
	i = 0;
	j = strlen(a);
	
	while ( i <= j) {
		
		if (a[i] == 'a' || a[i] == 'A') {
			a[i] = '4';
			printf("%c ", a[i]);
		}
		
		i++;	
	}
	

    return 0;
}
