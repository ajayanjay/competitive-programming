/* Program: Validasi_Vokal_Saiful.c
 * Deskripsi: Memeriksa apakah suatu karakter merupakan huruf vokal atau bukan
 * Nama:
 * Tanggal/versi: 
 */

#include <stdio.h>
#include <ctype.h>

int main () {
	char a;
	
	
	scanf("%c", &a);
	
	a = tolower(a);
	
	switch(a) {
		case 'a' : printf("true"); break;
		case 'i' : printf("true"); break;
		case 'u' : printf("true"); break;
		case 'e' : printf("true"); break;
		case 'o' : printf("true"); break;
		default: printf("false"); break;
	}
	return -1;
}