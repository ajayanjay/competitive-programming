#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int countkata(char input[], int N);

int main()
{
    int count = 0;

    char input[64];
    while (1) {
        scanf("%s", input);
        ++count;
        if (getchar() == '\n') break;
    }

    printf("%d", count);

    return 1; 
}

int maintest () {
    char input[10000];
    
    scanf("%[^\n]%*c", input);
    
    int len = strlen(input);
    
    printf("%d", countkata(input, len));
}

int countkata(char input[], int N) {
    
    int count = 0;
    int i = 0;
    while (i < N) {
        
        if (input[i] != ' ') {
            count++;
        }
        while (input[i] != ' ' && i < N) {
            i++;
        }
        i++;
    }
    
    return count;
}
