
#include <stdlib.h>
#include <stdio.h>

int myAtoi(const char *restrict s) {

	// get num length
	int numLength = 0;
	long int num = 0;

	int hasMetNegative = -1;

	while (1) {


		if (s[numLength] >= '0' && s[numLength] <= '9') {
			numLength++;
		} else if (s[numLength] == '-') {
			if (hasMetNegative == -1 && (numLength == 0 || s[numLength - 1] == ' ')) {
				hasMetNegative = numLength++;
			} else {
				break;
			}
		} else if (s[numLength] == ' ') {
			numLength++;
		} else {
            break;
        }
        

	}

	for (int i = hasMetNegative + 1; i < numLength; ++i) {
		if (s[i] == ' ') continue;
		num = 10 * num + (s[i] - '0');
	}

	if (hasMetNegative != -1) {
		if (num > INT_MAX) {
			num = INT_MIN;
		} else {
			num = -num;
		}
	}

	if (num > INT_MAX) {
		num = INT_MAX;
	}

	return num;
}

int main() {
	char a[50];

	scanf("%[^\n]%*c", a);

	printf("%d", myAtoi(a));

	system("pause");
}
