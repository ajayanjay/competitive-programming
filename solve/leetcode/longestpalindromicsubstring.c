#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindrome(const char* restrict s, int first, int last) {
    int middle = first + (last - first) / 2;

    for (int i = first; i <= middle; ++i)
        if (s[i] != s[last - (i - first)])
            return 0;
    return 1;
}

void copyString(char* to, const char* restrict source, int first, int last) {

    int len = last - first + 1;
    int i;

    for (i = 0; i < len; ++i) {
        to[i] = source[i + first];
    }
    
    to[i] = '\0';

}


char* longestPalindrome(const char* restrict s) {
    int len = strlen(s);

    int maxLen = 1;
    char* maxPalindrome = (char*)malloc((len + 1) * sizeof(char));
    
    maxPalindrome[0] = s[0]; maxPalindrome[1] = 0;

    if (len == 1) return maxPalindrome;

    for (int i = 0; i < len; ++i) {
        int j = len - 1;

        while (j > i) {

            while (s[i] != s[j] && j-- > i);
            //F.S same char or nah;
            
            if (isPalindrome(s, i, j)) {
    
                int currentLen = j - i + 1;

                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    copyString(maxPalindrome, s, i, j);
                }

            }

            --j;

        }

        if (len - i < maxLen) break;
        
    }
    
    return maxPalindrome;
}

int main() {

    char buffer[1024];

    scanf("%s", buffer);

    printf("%s", longestPalindrome(buffer));
    return 0;
}
