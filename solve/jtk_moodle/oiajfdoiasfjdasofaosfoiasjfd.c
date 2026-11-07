#include <stdio.h>

#define isGenap(a) a % 2 == 0

int main() {
	
    int a, b, x, y, count;
    
    scanf ("%d %d", &a, &b);
    x = (a*2) - 1;
    y = 1;
    
    for (int i = 1; i <= a; i++) {
    	
	    count = i;
        
		for (int j = 1; j <= b; j++) {
        
		    printf("%d ", count);
        
            count += isGenap(count) ? y : x;

        }
        
		x -= 2;
        y += 2;
        printf("\n");    
    }
}