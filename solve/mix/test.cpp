#include <iostream>
#include <stack>

using namespace std;

int test() {
	return 10;
}

int main() {

	int x = 1, y =1;

	(x += y) = 100;

	cout << x << ' ' << y << '\n';

	(x, y) = 200;

	cout << x << ' ' << y << '\n';

	(x > y ? ++x : ++y) = 300;

	cout << x << ' ' << y << '\n';

	(x = test() + x, y) = 10;

	cout << x << ' ' << y << '\n';

	(x ? x : y) = 100;

	(((((x += y) += y) += y) += y) += y) = x;

	((x += y, y > x ? x : y) = test() + x, x) = 300;


	int i = 0;
	for (printf("Init\n"); printf("Check\n"), i < 10; printf("Update\n"), i++) {
		
	}

	i = sizeof x;

	cout << i << '\n';

	return 0;
}