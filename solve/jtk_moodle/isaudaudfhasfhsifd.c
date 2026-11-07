/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define baris 25
#define kolom 25

void swap(char a[baris][kolom], int *c, int *b, int *x, int *y) {
	a[*b][*c] = ' ';
	a[*y][*x] = 'X';
}

void initializearray(char a[baris][kolom]) {
	for (int i = 0; i < baris; i++) {
		for (int j = 0; j < kolom; j++) {
			a[i][j] = ' ';
		}
	}
}

void printcurrent(char a[baris][kolom]) {
	system("cls");
	for (int i = 0; i < baris; i++) {
		for (int j = 0; j < kolom; j++) {
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

void move(int *x, int *y) {
	switch(getch()) {
		case 'w' : (*y)--; break;
		case 'a' : (*x)--; break;
		case 's' : (*y)++; break;
		case 'd' : (*x)++; break;
		default : return;
	}
}

int main() {

/* Kamus */
	char a[baris][kolom];
	char x;
	int Y, X, prevY, prevX;
/* Program */
	
	initializearray(a);
	X = 0;
	Y = 0;
	a[Y][X] = 'X';
	
	while (x != 'x') {
		printcurrent(a);
		prevY = Y;
		prevX = X;
		move(&Y, &X);
		swap(a, &prevY, &prevX, &Y, &X);
	}

    return 0;
}
