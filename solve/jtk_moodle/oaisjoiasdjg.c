#include <stdio.h>

int main() {
    
    int N;
    
    scanf("%d", &N);
    double a[N];
    
    for (int i = 0; i < N; i++) {
        scanf(" %d", &a[i]);
    }
    
    if (N % 2 == 0) {
        a[N/2] = (double) (a[N/2 - 1] + a[N / 2]) / 2;
    } 
    
    printf("%lf", (double) a[N/2]);
    
}