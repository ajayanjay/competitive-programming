/* File			: ingredient matching percentage */
/* Deskripsi	: me helping someone so lazy they had me program this bullcrap */
/* Nama / NIM	: Muhammad Azzar MH / 241524051 */
/* Tanggal		: 23 Oktober 2024 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

/* Kamus */
	char cakeA[16], cakeB[16], current;
	double N, percentage;
	int count, max, lenCakeA, lenCakeB;
	bool impostor;

/* Program */

	char lib[13] = "tgrpmacskfjno";

	scanf("%lf\n", &N);
	scanf("%[^\n]%*c", cakeA);
	scanf("%[^\n]%*c", cakeB);
	
	lenCakeA = strlen(cakeA);
	lenCakeB = strlen(cakeB);
	
	count = 0;
	
	for (int i = 0; i < lenCakeA; i += 2) {
		
		current = cakeA[i];
		
		impostor = true;
		
		//check to see if the cake has an impostor ingredient
		for (int j = 0; j < 13; j++) {
			if (current == lib[j]) {
				impostor = false;
				break;
			}
		}
		
		//if they do have an impostor among them, skip the current loop
		if (impostor) {
			continue;
		}
		
		// check to see if ingredient at A existed in B.
		// assign \0 is done to see if there's duplicated ingredient on both sides
		for (int k = 0; k < lenCakeB; k+=2) {
			if (current == cakeB[k]) {
				cakeB[k] = '\0';
				count++;
				break;
			}
		}
		
		
	}
	
	if (lenCakeA > lenCakeB) {
		max = lenCakeA / 2 + 1;
	} else {
		max = lenCakeB / 2 + 1;
	}
	
	percentage = (double) count * 100 / max;
	
	if (percentage >= N) {
		printf("sama");
	} else {
		printf("tidak sama");
	}
	
    return 0;
}
