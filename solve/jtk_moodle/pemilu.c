/* Program: Challenge05_Nama.c
 * Deskripsi: Pemilu
 * Nama:  M Azzar
 * Tanggal/versi: 
 * Compiler: 
 */

#include <stdio.h>

int prosesMax(int baris, int kolom);

int main() {
	int T, Ti, baris, kolom, hasil;
	scanf("%d", &T);
	
	for (Ti = 0; Ti < T; Ti++) { // untuk setiap kasus uji
	    scanf("%d %d", &kolom, &baris);
	    
	    hasil = prosesMax(baris, kolom);
	    
	    printf("%d\n", (hasil+1));

	}
	
	return 0;
}

int prosesMax(int baris, int kolom) {
	int a[baris][kolom];
	    
	for (int i = 0; i < baris; i++) {
    	for (int j = 0; j < kolom; j++) {
	  		scanf("%d", &a[i][j]);
		}
	}
	
	int max, maxindex;
	int sum;
	for (int j = 0; j < kolom; j++) {
		
		sum = 0;
		for (int i = 0; i < baris; i++) {
			sum += a[i][j];
		}
		
		if (j == 0) {
			max = sum;
			maxindex = j;
			continue;
		}
		
		if (sum > max) {
			max = sum;
			maxindex = j;
		}
		
	}
	return maxindex;
}
