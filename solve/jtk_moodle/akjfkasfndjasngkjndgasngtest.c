/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <conio.h>

int inputArrow();

int main() {

/* Kamus */
	char a;

/* Program */

	a = 'x';

	do
	{
		switch(inputArrow()) {
			case 0: printf("UP!\n"); break;
			case 1: printf("LEFT!\n"); break;
			case 2: printf("DOWN!\n"); break;
			case 3: printf("RIGHT!\n"); break;
			default: break;
		}
		
	} while (a != 'w');

    return 0;
}

int inputArrow(){
	
	char a = getch();
	
	if (a == -32) {
		switch (getch()) {
				case 'H': return 0;
				case 'K': return 1;
				case 'P': return 2;
				case 'M': return 3;
		}
	} else {
		return -1;
	}
	
}