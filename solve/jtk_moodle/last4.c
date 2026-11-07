#include <stdio.h>

int main () {
    
    int a, b, count;
    scanf("%d %d", &a, &b);
    
    count = 0;
    
    for (int i = a + 1; i < b; i++)
        if (i % 10 == 4)
            count++;
    
    count = b - a - 1 - count;
    printf("%d", count);
}