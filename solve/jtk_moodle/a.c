/*
Deskripsi : sandi
Nama /Author : M Azzar MH
Tanggal/versi : Senin, 21 Oktober 2024
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    //tulis jawaban anda dibawah ini
    char input[31], currentchar, groupbefore;

    int group;

    scanf("%[^\n]%*c", input);

    int len = strlen(input);

    for (int i = 0; i < len; ++i) {
        currentchar = tolower(input[i]);
        
        if (currentchar == ' ') {
            printf("0 ");
            continue;
        }

        // wat = (a - 93 / 3) + 1;
        // (wat - 1) * 3 + 97 = a
        char a1 = group - 1 - (group - 97) / 3;

        group = (currentchar - 97) / 3 + 1;
 
        if (group == input[i-1]) printf("-1 ");

        for (int j = 0; j <= currentchar - a1; ++j)
            printf("%d ", group);

        input[i] = group;
    }

}
