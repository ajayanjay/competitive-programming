#include <stdio.h>

int main(int argc, char const *argv[]){
	int x = 0, d = 0;

	scanf("%d %d", &x, &d);

	if (x*2 > d) printf("take it");
	else printf("double it");
	
	return 0;
}