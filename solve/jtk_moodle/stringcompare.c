/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */
	char k1[10], k2[10];
	int count1 = 0, count2 = 0, len1, len2, diff;

/* Program */
	
	scanf("%s\n", k1);
	
	scanf("%s", k2);
	
	len1 = strlen(k1);
	len2 = strlen(k2);
	
	for (int i = 0 ; i < len1 ; i++) {
		if (k1[i] != k2[i]) {
			printf("%+d\n%d", (k1[i] - k2[i]), i + 1);
			return 0;
		}
	}
	printf("0\n0");
	
    return 0;
}
