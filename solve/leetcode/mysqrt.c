#include <stdlib.h>
#include <stdio.h>


int mySqrt(int x) {

	int i = -1;

	while ((++i) * i <= x);

	return --i;

}

int main() {
	int x;

	scanf("%d", &x);

	printf("%d", mySqrt(x));
	system("pause");
}