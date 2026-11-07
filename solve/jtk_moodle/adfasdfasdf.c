#include <stdio.h>

int main() {

    int N;
    double median;
    
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf(" %d", &a[i]);
    }
    
    if (N % 2 == 0) {
        median = (double) (a[N/2] + a[N / 2 + 1]) / 2;
    } else {
        median = (double) (a[N/2]);
    }
    
    printf("%lf", median);
    
}