#include <stdio.h>
#include <stdbool.h>

#define abs(x) (((x) < 0) ? (-x) : (x))

typedef struct {
	int x, y;
} point_t;

int main(void) {

	point_t a, b, c, d;

	scanf("%d %d", &a.x, &a.y);
	scanf("%d %d", &b.x, &b.y);
	scanf("%d %d", &c.x, &c.y);
	scanf("%d %d", &d.x, &d.y);

	point_t delta[4], diag[2];

	int test = a.x - b.x;

	delta[0].x = a.x - b.x;
	delta[0].y = a.y - b.y;

	delta[1].x = b.x - c.x;
	delta[1].y = b.y - c.y;

	delta[2].x = c.x - d.x;
	delta[2].y = c.y - d.y;

	delta[3].x = d.x - a.x;
	delta[3].y = d.y - a.y;

	diag[0].x = a.x - c.x;
	diag[0].y = a.y - c.y;

	diag[1].x = b.x - d.x;
	diag[1].y = b.y - d.y;

	diag[0].x = abs(diag[0].x);
	diag[0].y = abs(diag[0].y);

	diag[1].x = abs(diag[1].x);
	diag[1].y = abs(diag[1].y);

	if (diag[0].x != diag[1].y || diag[0].y != diag[1].x) {
		printf("NAO");
		return 0;
	}

	for (int i = 0; i < 4; ++i) {
		delta[i].x = abs(delta[i].x);
		delta[i].y = abs(delta[i].y);
	}
		

	delta[0].x += delta[1].x;
	delta[0].y += delta[1].y;

	delta[2].x += delta[3].x;
	delta[2].y += delta[3].y;

	if (delta[0].x == delta[2].x && delta[0].y == delta[2].y) {
		printf("SIM");
	} else {
		printf("NAO");
	}

	/*
		3 3
		9 3
		6 6
		6 0

		6 0
		3 3
		0 6
		3 3
	*/

	return 0;
}

/*
	1 0
	2 1
	1 2
	0 1

	1 1
	1 1
	1 1
	1 1
*/