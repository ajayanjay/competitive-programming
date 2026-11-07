#include <stdio.h>
#include <stdlib.h>

#define ll long long

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);

        ll *a = (ll*) malloc(n * sizeof(ll));
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }

        while (q--) {
            ll x;
            scanf("%lld", &x);

            for (int i = 0; i < n; ++i) {
                x %= a[i];
            }

            printf("%lld\n", x);
        }

        free(a);
    }

    return 0;
}
