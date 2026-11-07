#include <stdio.h>

#define ROMAN_CHAR_AMOUNT 4

const int roman_digits[ROMAN_CHAR_AMOUNT] = {1, 5, 10, 50};

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int i = 0; i < ROMAN_CHAR_AMOUNT; ++i) {
			int digit = roman_digits[i];
		}	
	}
}

