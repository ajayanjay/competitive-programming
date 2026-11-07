/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
int N, kolom, baris, count, fillx, filly;

/* Program */
	scanf("%d", &N);
	
	int a[N][N];
	
	count = 1;
	kolom = N - 1;
	baris = 0;
	
	while (baris < N) {
		
		a[baris][kolom] = count;
		
		fillx = kolom + 1;
		filly = baris + 1;
		
		while (fillx < N && filly < N) {
			count++;
			
			a[filly][fillx] = count;
			
			fillx++;
			filly++;
		}
		
		if (kolom > 0) {
			kolom--;
		} else {
			baris++;
		}
		
		count++;
		
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

    return 0;
}
