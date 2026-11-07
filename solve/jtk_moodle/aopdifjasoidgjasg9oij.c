/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <ctype.h>

int main() {

/* Kamus */
	const char lib[9] = "jtkpolban";
	char find[2];

/* Program */
	scanf("%c %c", &find[0], &find[1]);
	
	find[0] = tolower(find[0]);
	find[1] = tolower(find[1]);
	
	for (int i = 0; i < 8; i++) {
		if (find[0] == lib[i + 1] && find[1] == lib[i]) {
			printf("ada");
			return 0;
		}
	}

	printf("tidak ada");
    return 0;
}
