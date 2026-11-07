#include <stdio.h>

int main() {
    
    long long int a,b,c,d, e,f;
    
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    
    e = a * d + c * b;
    f = d * b;
    
    a = e;
    b = f;
    
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    
    e /= b;
    f /= b;
    
    printf("%d %d", e, f);
}