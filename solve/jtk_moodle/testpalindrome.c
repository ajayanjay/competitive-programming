/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char input[]);

int main() {

/* Kamus */
	char input[10000][200];
	int count = 0;
/* Program */
	for (int i = 0; i< 10000; i++) {
		scanf("%s", input[i]);
		++count;
		
		if (isPalindrome(input[i])) {
			printf("%s ", input[i]);
		}
		
		if (getchar() == '\n') break;
	}
	

    return 0;
}

bool isPalindrome(char input[]) {
	int len = strlen(input);
	
	if (len == 1) {
		return true;
	}
	
	for (int i = 0; i < len / 2; i++) {
		if (input[i] != input[len - i - 1]) {
			//printf("%c %c", input[i], input[len - i - 1]);
			return false;
		}
	}
	
	return true;
}