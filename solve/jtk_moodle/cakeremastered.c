/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>

int main() {

/* Kamus */
	char cake1[8], cake2[8];
	int count = 0, count2 = 0, cakes = 0, max;
	double N, percentage;
	
/* Program */
	scanf("%lf\n", &N);
	
	for (int i = 0; i < 8; ++i) {
		scanf("%c", &cake1[i]);
		++count;
		if (getchar() == '\n') break;
	}
	
	for (int i = 0; i < 8; ++i) {
		scanf("%c", &cake2[i]);
		
		++count2;
		
		for (int j = 0 ; j < count; ++j) {
			if (cake2[i] == cake1[j]) {
				cake1[i] = '0';
				++cakes;
				break;
			}
		}
		
		if (getchar() == '\n') break;
	}	
	
	max = (count2 > count) ? count2 : count;
	
	percentage = (double) cakes / max * 100;
	
	if (percentage >= N) {
		printf("sama");
	} else {
		printf("tidak sama");
	}
	
    return 0;
}
