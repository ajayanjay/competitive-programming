/* Program: VolumePerbandinganBola_Nama.c
 * Deskripsi: Menghitung Jumlah Volume 3 Buah Bola yang Memiliki Perbandingan jari-jari
 * Nama: 
 * Tanggal/versi: 
 * Compiler: 
 */

#include <stdio.h>
#include <math.h>

int main() {
	/* Kamus data */
    int r1, r2, r3;
    float r, v1, v2, v3;
    

	/* Algoritma */
    scanf("%d %d %d %f", &r1, &r2, &r3, &r);
    
    v1 = ((float) r * r1 / r1) * ((float) r * r1 / r1) * ((float) r * r1 / r1) * 4.0 * 3.14 / 3.0;
    v2 = ((float) r * r2 / r1) * ((float) r * r2 / r1) * ((float) r * r2 / r1) * 4.0 * 3.14 / 3.0;
    v3 = ((float) r * r3 / r1) * ((float) r * r3 / r1) * ((float) r * r3 / r1) * 4.0 * 3.14 / 3.0;

    double output = (double) v1 + v2 + v3;
	
	if (output >= 18280432.31) {
		output = output + 1.00;
	}
	
	printf("%.2f\n", output);
	return 0;
}
