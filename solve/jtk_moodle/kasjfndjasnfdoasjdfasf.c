#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main () {
    
    int input[10], j;
    bool prime;
    
    int count = 0;
    
    for (int i = 0; i < 10; i++) {
        
        scanf("%d ", &input[i]);
        
        if (input[i] < 2) {
        	continue;
		} 
        
        prime = true;
        
        for (j = 2 ;j <= sqrt(input[i]); j++) {
        	if (input[i] % j == 0) {
        		prime = false;
        		break;
			}
		}
        
        if (prime) {
            count++;
        }
        
        
    }
    
    printf("%d", count);
    
    return 0;
}