/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char a[30];
	int num;

/* Program */
	scanf("%[^\n]%*c", a);
	
	scanf("%d", &num);
	
	for (int i = strlen(a) - num; i < strlen(a); i++ ) {
		printf("%c", a[i]);
	}

    return 0;
}
