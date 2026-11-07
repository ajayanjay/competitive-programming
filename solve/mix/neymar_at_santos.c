#include <stdio.h>

#define ull unsigned long long

int main(void) {

	ull p;
	int r;
	int g;
	int x;

	scanf("%llu %d %d %d", &p, &r, &g, &x);

	ull total_neymar_real = g * x; // goal * real each goal.

	// harusnya jawabannya p * g * x, tapi karena g * x ini tuh BISA melebihi r. harus di cek

	// karena ga mungking teacher nya bayar di atas gaji nya, harus di cek juga.
	ull min = total_neymar_real > r ? r : total_neymar_real;

	ull answer = min * p;

	printf("%llu", answer);

	return 0;
}