#include <stdio.h>
#include <string.h>

int main (){
    
    char input[40];
    char find[3];
    int count = 0;
    
    gets(strlwr(input));

    scanf("%s", strlwr(find));

    int len = strlen(input) - 2; 

    int i = 0;
    while (i < len) {

        int j = 0;
        while (input[i] == find[j]) {
            ++i; ++j;
        }

        if (j >= 2) ++count; 

    }
    
    printf("%d", count);
    
}
