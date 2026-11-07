#include <stdio.h>

int main() {
    
    int a, sum, count;
    
    scanf("%d", &a);
    int nilai[a];
    
    sum = 0;
    count = 0;
    
    for (int i = 0; i < a; i++) {
        scanf(" %d", &nilai[i]);
        sum += nilai[i];
    }
    
    double avg = (double) sum / a;
    
    for (int i = 0; i < a; i++) {
        if (nilai[i] < avg) {
            count++;
        }
    }
    
    printf("%d", count);
    
}