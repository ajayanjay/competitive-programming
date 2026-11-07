/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point;

int main() {

/* Kamus */
	int M, kuadran, count;

/* Program */
	scanf("%d", &M);
	
	Point arr[M];
	count = 0;
	
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	
	scanf("%d", &kuadran);

	switch (kuadran) {
		case 1:
			for (int i = 0; i < M; i++) {
				if (arr[i].x > 0 && arr[i].y > 0) {
					count++;
				}
			}
			break;
		case 2:
			for (int i = 0; i < M; i++) {
				if (arr[i].x < 0 && arr[i].y > 0) {
					count++;
				}
			}
			break;
		case 3:
			for (int i = 0; i < M; i++) {
				if (arr[i].x < 0 && arr[i].y < 0) {
					count++;
				}
			}
			break;
		case 4:
			for (int i = 0; i < M; i++) {
				if (arr[i].x > 0 && arr[i].y < 0) {
					count++;
				}
			}
			break;
		default: return -1;
	}

	printf("%d", count);

    return 0;
}
