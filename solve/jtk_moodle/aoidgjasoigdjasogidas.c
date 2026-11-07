/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>

int main() {

/* Kamus */

    const int lib[128] = {
        ['A'] = 1, ['B'] = 2,
        ['D'] = 1, ['O'] = 1,
        ['P'] = 1, ['Q'] = 1,
        ['R'] = 1
    };

    char input[51];
    int count = 0;
    int length;

/* Program */

    fgets(input, 51, stdin);

    length = strlen(input);

    for (int i = 0; i < length; ++i)
        count += lib[input[i]];

    printf("%d", count);

/*
AaBbDdegoOpPqQR
*/
    return 0;
}
