#include <stdio.h>

int main(void) {

	char buffer[500];

	fgets(buffer, 500, stdin);

	printf("Why'd the chicken cross the road? to get to the other side!");

	return 0;
}