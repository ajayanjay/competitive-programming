
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int reverses(int x){

	if (x == INT_MIN || x == INT_MAX) return 0;

	const long int tens[10] = {
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
        1000000000
	};

	int isNegative;

	if ((isNegative = (x < 0 ? 1 : 0))) 
		x = -(x);

	long int temp = x;

	int ten = 0;

	while ((temp /= 10) > 0) ++ten;

	if (ten > 9) return 0;

	int c = tens[ten];

	for (int i = 0; i <= ten; ++i) {

		temp += (x/c) * tens[i];

		x %= c; c /= 10;

	}

	if (temp < INT_MIN || temp > INT_MAX) return 0;

	if (isNegative) temp = -(temp);

	return temp;

}

int reverse (int x) {
	int temp = 0;

	while (x != 0) {
		temp = temp * 10 + x % 10;
		x /= 10;
	}
	return temp;
}

int main(int argc, char const *argv[])
{
	int a;
	scanf("%d", &a);

	printf("%d", reverse(a));

	system("pause");

	return 0;
}