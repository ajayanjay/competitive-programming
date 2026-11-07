/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	int m, n, n1, p, sum;

/* Program */
	scanf("%d %d", &m, &n);
	int arr1[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr1[i][j]);
		}
	}
	
	scanf("%d %d", &n1, &p);
	int arr2[n1][p];
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < p; j++) {
			scanf(" %d", &arr2[i][j]);
		}
	}
	
	int arr3[m][p];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++){
			
			//okay this is nuts lol
			sum = 0;
			for (int k = 0; k < n; k++) {
				sum += (arr1[i][k] * arr2[k][j]);
			}
			
			arr3[i][j] = sum;
			printf("%d ", arr3[i][j]);
			
		}
		printf("\n");
		
	}

    return 0;
}
