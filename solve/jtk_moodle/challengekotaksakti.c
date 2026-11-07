/* Program: Challenge04_Nama.c
 * Deskripsi: 
 * Nama: M Azzar MH
 * Tanggal/versi: 
 * Compiler: 
 */

#include <stdio.h>

int pola(int mulai, int N);
int startingPola(int);

int main() {
	int T, Ti, besar, mulai, hasil;
	scanf("%d", &T);
	
	for (Ti = 0; Ti < T; Ti++) { // untuk setiap kasus uji
	    scanf("%d", &besar);
	    printf("%d\n", pola(startingPola(besar - 3), besar));
	}
	
	return 0;
}

int pola(int mulai, int N) {

    int sum = mulai;
    for (int i = 1; i < N; i++) {
        sum += 3;
        mulai += sum;
    }
    
    return mulai;
}

int startingPola(int besar) {
	
	int mulai = 2;

	for (int i = 0; i < besar; ++i)
		mulai += 2 + i;

	return mulai;
}
