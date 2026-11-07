#include <stdio.h>
#include <string.h>

int isPalindrome(const char*, int);

int main () {

    char input[64];
    int count = 0;
    
    do
    {
        scanf("%s", input);

        int len = strlen(input);

        count += isPalindrome(input, len);

    } while (getchar() == '\r');

    printf("%d", count);
}

int isPalindrome(const char* string, int len) {

    int half = len / 2;

    for (int i = 0; i < half; ++i)
        if (string[i] != string[len - i])
            return 0;

    return 1;

}
