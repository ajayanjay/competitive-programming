/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Point;

int main() {

	/* Kamus */
	int r, jarakX, jarakY, jarak;
	Point p, t;

	/* Program */
	scanf("%d %d", &p.x, &p.y);
	scanf("%d", &r);
	scanf("%d %d", &t.x, &t.y);
	
	jarakX = p.x - t.x;
	jarakY = p.y - t.y;
	
	jarak =  sqrt(jarakX*jarakX + jarakY*jarakY);
	
	if (jarak == r) printf("tepat pada lingkaran");
	else if (jarak == 0) printf("tepat pada titik pusat");
	else if (jarak > r) printf("di luar lingkaran");
	else printf("di dalam lingkaran");

    return 0;
}
