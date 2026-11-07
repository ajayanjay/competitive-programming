/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
// Kamus Function / Procedure
void kali (int a, int b, int *hasil, int *hasil2);
void swap (int *a, int *b);

int main() {

/* Kamus Data*/
	int a, b, goblok, anjing;

/* Program */
	scanf("%d %d", &a, &b);
	
	goblok = 70;
	
	anjing = 50;
	
	kali (a, b, &goblok, &anjing);
	
	swap(&goblok, &anjing);
		
	printf("%d %d", goblok, anjing);
	
	//printf("\n%d %d", a, b);	

    return 0;
}

//			20		5		goblok		anjing
void kali (int a, int b, int *hasil, int *hasil2) {
//	hasil, parameter passing by address


// kalo output, wajib bintang
// kalau input, ga wajib ga ada bintang
// kalo ga ada bintang, wajib input

// kalo input output, wajib bintang

//	goblok = 20 * 5
	*hasil = a * b;
	
//	anjing = 20 - 5
	*hasil2 = a - b;
	
	a = 0;
	
	b = 0;
}

void swap (int *a, int *b) {
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}


//return 1;
//return 2;