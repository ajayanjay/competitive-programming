/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char input[26], sama[26];
	int k, len;

/* Program */
	scanf("%[^\n]%*c", input);

	len = strlen(strlwr(input));
	
	k = 0;
	for (int i = 0; i < len; i++)
		if (!strchr(sama, input[i])) 
			sama[k++] = input[i];
	
	printf("%d", k);

    return 0;
}