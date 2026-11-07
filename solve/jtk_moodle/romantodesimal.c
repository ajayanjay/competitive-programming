#include <stdio.h>

int main() {

	int a, repetition, j, count;
	const int lib[3][2] = {{'V', 5}, {'L', 50},{'D', 500}};
	const int tens[4][2] = {{'I', 1}, {'X', 10}, {'C', 100}, {'M', 1000}};
	char roman[50];

	scanf("%d", &a);
	//IVXLCDM
	//2795
	//MMDCCXCV


	count = 0;
	j = 3;
	//rather disgusting code
	while (a > 0) {

		if (j == 3) { // cases for thousands

			repetition = a / tens[j][1];
			for (int i = 1; i <= repetition; i++) {
				a -= tens[j][1];
				roman[count] = (char) tens[j][0];
				++count;
			}
			--j;

		} else {

			if (a >= tens[j][1] * 9) { // cases like IX XC CM
				a -= (tens[j][1] * 9);
				roman[count] = tens[j][0];
				roman[count + 1] = tens[j+1][0];

				count += 2;

			} else if (a >= tens[j][1] * 5) { //bruh, cases like VIII
				a -= lib[j][1];
				roman[count] = lib[j][0];

				++count;

				while (a >= tens[j][1]) {
					a -= tens[j][1];
					roman[count] = tens[j][0];
					++count;
				}

			} else if (a >= tens[j][1] * 4) { // IV
				a -= (tens[j][1] * 4);
				roman[count] = tens[j][0];
				roman[count + 1] = lib[j][0];
				count += 2;

			} else {
				while (a >= tens[j][1]) { // III XXX
					a -= tens[j][1];
					roman[count] = tens[j][0];
					++count;
				}
			}
			--j;
		}
	}


	for (int i = 0; i < count; i++) {
		printf("%c", roman[i]);
	}
}
