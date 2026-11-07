/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
} Point;

int main() {

/* Kamus */
	Point M[5], N[5];
/* Program */
	
	for (int i = 0; i < 5; i++) {
		scanf("%d %d", &M[i].x, &M[i].y);
	}
	
	for (int i = 0; i < 5; i++) {
		scanf("%d %d", &N[i].x, &N[i].y);
		if (N[i].x != M[i].x || N[i].y != M[i].y) {
			printf("tidak sama");
			return -1;
		}
	}
	
	printf("sama");
    return 0;
}
