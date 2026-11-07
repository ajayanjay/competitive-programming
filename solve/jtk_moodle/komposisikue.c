/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

#define max(a,b) a > b ? a : b


int main() {

/* Kamus */
	int p, q, count;
	double N;
	const char* lib[] = {"telur", "gula", "ragi", "tepung", "mentega", "air", "coklat", "susu", "kentang", "fermipan", "keju", "nanas", "sosis"};
/* Program */

	count = 0;

	scanf("%lf", &N);

	scanf("%d\n", &p);
	char k[p][8];
	for (int i = 0; i < p; i++) {
		scanf("%[^\n]%*c", k[i]);
	}

	scanf("%d\n", &q);
	char l[q][8];
	for (int i = 0; i < q; i++) {
		scanf("%[^\n]%*c", l[i]);

		for (int j = 0; j < p; j++) {
			if (strcmp(k[j], l[i]) == 0) {
				++count;
				break;
			}
		}
	}

	double percentage = (double) count * 100 / max(p,q);

	if (percentage >= N) {
		printf("sama");
	} else {
		printf("tidak sama");
	}

    return 0;
}
