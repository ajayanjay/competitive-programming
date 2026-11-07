#include <stdio.h>

int main() {
    int a, sum;
    scanf("%d", &a);
    
    sum = a;
    
    for (int i = 2; i <= 15; i++) {
        printf("%d ", sum);
        if ((i-1) % 3 == 0) {
            sum += 5;
        } else if ((i) % 3 == 0) {
            sum += 4;
        } else if ((i + 1) % 3 == 0) {
            sum += 3;
        }
    }
}