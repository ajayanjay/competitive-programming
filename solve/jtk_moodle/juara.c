/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

/* Kamus */
	int n, m;
	bool yes;

/* Program */
	
	yes = false;

	scanf("%d\n", &n);
	
	char catur[n][100];
	for (int i = 0; i < n; i++){
		scanf("%[^\n]%*c", catur[i]);
	}
	
	scanf("%d\n", &m);
	char badminton[m][100];
	for (int i = 0; i < m; i++){
		scanf("%[^\n]%*c", badminton[i]);
	}


	for (int i = n - 1; i >= 0; i--) {
		
		for (int j = 0 ;j < m; j++) {
			if (strcmp(catur[i], badminton[j]) == 0) {
				printf("%s\n", catur[i]);
				yes = true;
			}
		}
		
	}

	if (!yes) {
		printf("tidak ada sang juara");
	}
	
    return 0;
}
